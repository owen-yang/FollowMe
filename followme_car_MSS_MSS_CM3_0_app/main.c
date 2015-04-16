#include "bool.h"
#include "car.h"
#include "magnetometer.h"
#include "bluetooth.h"
#include "drivers/CoreUARTapb/core_uart_apb.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
//	initCar();
	enable_LSM();

	// CAR DEMO

//	int count = 0;
//	int cycle = 0;
//	while( 1 )
//	{
//		if (count++ >= 2000000) {
//			cycle++;
//			count = 0;
//		}
//
//		switch (cycle) {
//		case 0:
//			moveCarForward(50);
//			break;
//		case 1:
//			moveCarReverse(50);
//			break;
//		case 2:
//			rotateCarRight(30);
//			break;
//		case 3:
//			rotateCarLeft(30);
//			break;
//		case 4:
//			turnCarRight(40);
//			break;
//		case 5:
//			turnCarLeft(40);
//			break;
//		case 6:
//			stopCar();
//			break;
//		default:
//			cycle = 0;
//			break;
//		}
//	}

//	initBluetooth();
//	enableScan();

	UART_instance_t g_uart;
	UART_init(&g_uart, 0x40050100UL, 650, (DATA_8_BITS | NO_PARITY));

	char *ready = "POOPLORD420";
	UART_polled_tx_string(&g_uart, ready);

	char g_rx_buff[100];
	uint32_t g_rx_buff_size = 0;

	while (1) {
		char buff[40];
		size_t size = UART_get_rx(&g_uart, buff, sizeof(buff));

		int i;
		bool endFlag = false;
		for (i = 0; i < size; ++i) {
			g_rx_buff[g_rx_buff_size++] = buff[i];
			if (buff[i] == '\n') {
				endFlag = true;
				break;
			}
		}

		if (endFlag) {
			g_rx_buff[g_rx_buff_size] = '\0';
			printf("%s\n\r", g_rx_buff);
			g_rx_buff_size = 0;

			char *string = strdup(g_rx_buff);
			char *elems[5];
			uint8_t elemsSize = 0;
			char *elem = strtok(string, " ");
			while (elem) {
				elems[elemsSize++] = elem;
				elem = strtok(NULL, " ");
			}

			printf("x: %s, y: %s, z: %s\n\r", elems[0], elems[1], elems[2]);

//			for (i = 0; i < elemsSize; ++i) {
//				printf("val: %d\n\r", atoi(elems[i]));
//			}

			free(string);
		}


//		read_LSM();
//		printf("%f\n\r", magToDegrees(LSM_data.mag_x, LSM_data.mag_y));

//		printf("distance: %f\n\r", distMint);

//		if (distMint > 8) {
//			moveCarForward(50);
//		} else if(distMint > 2){
//			moveCarForward(10);
//		} else {
//			stopCar();
//		}
	}
}
