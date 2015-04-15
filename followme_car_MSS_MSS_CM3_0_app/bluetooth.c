
#include "bluetooth.h"
#include "drivers/mss_uart/mss_uart.h"
#include "bool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "utilities.h"

#define RX_BUFF_SIZE    100
char g_rx_buff[RX_BUFF_SIZE];
uint32_t g_rx_buff_size = 0;

void uart1_rx_handler( mss_uart_instance_t * this_uart )
{
	char buff[100];
	uint8_t size = MSS_UART_get_rx( this_uart, buff, sizeof(buff));

	int i;
	bool endFlag = false;
	for (i = 0; i < size; ++i) {
		g_rx_buff[g_rx_buff_size++] = buff[i];
		if (buff[i] == '\r') {
			endFlag = true;
		}
	}

	if (endFlag) {
		// end of transmission
		g_rx_buff[g_rx_buff_size] = '\0';
//		printf("%s", g_rx_buff);

		char *string = strdup(g_rx_buff);
		char *elems[20];
		uint8_t elemsSize = 0;
		char *elem = strtok(string, " ");
		while (elem) {
			elems[elemsSize++] = elem;
			elem = strtok(NULL, " ");
		}

		// check for mint beacon's Bluetooth address
		if (!strcmp(elems[2], "EBB9450632D5")) {
			for (i = 0; i < elemsSize; ++i) {
				if (!strcmp(elems[i], "R")) {
					char *ptr;
					int raw = strtol(elems[i+1], &ptr, 16);

					// if negative 8-bit value, sign extend
					if (raw & 0x00000080) {
						raw |= 0xffffff00; // sign extend
					}

//					shiftUpArrayInt(rssiMintArr, RSSI_MINT_ARR_SIZE);
//					rssiMintArr[0] = raw;
//					rssiMint = avgArrayInt(rssiMintArr, RSSI_MINT_ARR_SIZE)

					// update the LPF rssi array
					shiftUpArrayFloat(lpfRssiMintArr, RSSI_MINT_ARR_SIZE);
					lpfArrayFloat(lpfRssiMintArr, RSSI_MINT_ARR_SIZE, raw);

					shiftUpArrayFloat(distMintArr, DIST_MINT_ARR_SIZE);
					// RSSI = -10n*log10(d)+A
					// (A-RSSI)/(10n) = log10(d)
					// d = pow(10, (A-RSSI)/(10n))
					// where
					// RSSI = measured rssi; n = propagation constant (n=2 for free space); A = measured rssi at 1m; d = distance
					const int RSSI_REF_MINT = -61;
					const float PROPAGATION_CONSTANT = 2.0;

					distMintArr[0] = pow(10, (float)(RSSI_REF_MINT - lpfRssiMintArr[0]) / (PROPAGATION_CONSTANT*10));
					distMint = avg80ArrayFloat(distMintArr, DIST_MINT_ARR_SIZE);

					printf("Mint dist: %f\n\r", distMint);
					break;
				}
			}
		}
		free(string);

		// reset buffer
		g_rx_buff_size = 0;
	}
}

/**
 * Returns the length of a Melody Smart command
 */
int lengthOfCommand(char *command) {
	int i;
	for (i = 0; ; ++i) {
		if (command[i] == '\r') {
			break;
		}
	}
	return i+1;
}

/**
 * Initializes UART 1 with the following settings:
 *
 * 9600 baud
 * 8 data bits
 * 1 stop bit
 * no parity bit
 */
void initUART() {
	MSS_UART_init(&g_mss_uart1, MSS_UART_9600_BAUD, MSS_UART_DATA_8_BITS | MSS_UART_ONE_STOP_BIT | MSS_UART_NO_PARITY);
	MSS_UART_set_rx_handler(&g_mss_uart1, uart1_rx_handler, MSS_UART_FIFO_SINGLE_BYTE );
}

static char* CMD_CENT_ON = "SET CENT=ON\r";
static char* CMD_CENT_OFF = "SET CENT=OFF\r";
static char* CMD_WRT = "WRT\r";
static char* CMD_RST = "RST\r";

typedef char* Command;

/**
 * Sends a command to the BC118 module.
 */
void sendCommand(Command c) {
	MSS_UART_polled_tx(&g_mss_uart1, c, lengthOfCommand(c));
}

/**
 * Initializes the BC118 module and sets up for commands.
 */
void initBluetooth() {
	initUART();
	sendCommand("SET ACON=OFF\r");
//	sendCommand("DCN\r");
}

/**
 * Turns on scanning mode
 */
void enableScan() {
	sendCommand(CMD_CENT_ON);
	sendCommand(CMD_WRT);
	sendCommand(CMD_RST);
}

/**
 * Turns on advertising mode
 */
void enableAdv() {
	sendCommand(CMD_CENT_OFF);
	sendCommand(CMD_WRT);
	sendCommand(CMD_RST);
}

/**
 * Attempts to connect to the given address. The address should be
 * a 12 hex digit value.
 */
void connectToAddress(const char* address) {
	char buffer[50];
	sprintf(buffer, "CON %s 1\r", address);
	sendCommand(buffer);
}

