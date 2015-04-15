#include "magnetometer.h"

#include <stdio.h>

LSM_data_struct LSM_data;

void write8(const uint8_t reg, uint8_t value)
{
	uint8_t serial_addr;

	// this is correct assuming we're not using the temperature
	// sensing capabilities which is true

	if (reg < 0x20) serial_addr = MAGNET_TARGET_ADDRESS;
	else serial_addr = ACCEL_TARGET_ADDRESS;

	uint8_t data[] = {reg, value};
	MSS_I2C_write
	(
		&g_mss_i2c1,
		serial_addr,
		data, sizeof(data),
		MSS_I2C_RELEASE_BUS
	);

	MSS_I2C_wait_complete(&g_mss_i2c1, MSS_I2C_NO_TIMEOUT);
}

void read_reg(const uint8_t reg, uint8_t *buf, size_t size)
{
	uint8_t serial_addr;

	// this is correct assuming we're not using the temperature
	// sensing capabilities which is true

	if (reg < 0x20) serial_addr = MAGNET_TARGET_ADDRESS;
	else serial_addr = ACCEL_TARGET_ADDRESS;

	MSS_I2C_write_read
	(
		&g_mss_i2c1,
		serial_addr,
		&reg, sizeof(reg),
		buf, size,
		MSS_I2C_RELEASE_BUS
	);

	MSS_I2C_wait_complete(&g_mss_i2c1, MSS_I2C_NO_TIMEOUT);
}

void enable_LSM()
{
	MSS_I2C_init
	(
		&g_mss_i2c1,
		0x10u,
		MSS_I2C_PCLK_DIV_256
	);

	MSS_UART_init
	(
	    &g_mss_uart1,
	    MSS_UART_9600_BAUD,
	    MSS_UART_DATA_8_BITS | MSS_UART_NO_PARITY | MSS_UART_ONE_STOP_BIT
	);

	// enable accelerometer
	write8(0x20, 0x57);

	// enable magnetometer
	write8(0x00, 0x10);
	write8(0x01, 0x20);
	write8(0x02, 0x00);
}

void read_LSM()
{
	uint8_t desired_reg = 0x03;
	uint8_t buf[] = {0, 0, 0, 0, 0, 0};

	read_reg(desired_reg, buf, sizeof(buf));
	// higher bytes are first, x z y
	LSM_data.mag_x = (int16_t)(buf[1] | ((int16_t)buf[0] << 8u));
	LSM_data.mag_y = (int16_t)(buf[5] | ((int16_t)buf[4] << 8u));
	LSM_data.mag_z = (int16_t)(buf[3] | ((int16_t)buf[2] << 8u));

	desired_reg = 0x28;

	read_reg(desired_reg, buf, sizeof(buf));
	// lower bytes are first, x y z
	LSM_data.acc_x = (int16_t)(buf[0] | ((int16_t)buf[1] << 8));
	LSM_data.acc_y = (int16_t)(buf[2] | ((int16_t)buf[3] << 8));
	LSM_data.acc_z = (int16_t)(buf[4] | ((int16_t)buf[5] << 8));

}

#define PACKET_SIZE 40

void send_over_XBee()
{
	char buff[PACKET_SIZE];
	int buffSize = 0;

	buffSize += sprintf(&buff[buffSize], "%d ", LSM_data.acc_x);
	buffSize += sprintf(&buff[buffSize], "%d ", LSM_data.acc_y);
	buffSize += sprintf(&buff[buffSize], "%d ", LSM_data.acc_z);
	buffSize += sprintf(&buff[buffSize], "%d ", LSM_data.mag_x);
	buffSize += sprintf(&buff[buffSize], "%d ", LSM_data.mag_y);
	buffSize += sprintf(&buff[buffSize], "%d", LSM_data.mag_z);
	buff[buffSize++] = '\n';
	buff[buffSize++] = '\0';

//	uint8_t data[LSM_DATA_TOTAL_SIZE] =
//					   { LSM_data.acc_x >> 8u, LSM_data.acc_x,
//						 LSM_data.acc_y >> 8u, LSM_data.acc_y,
//						 LSM_data.acc_z >> 8u, LSM_data.acc_z,
//						 LSM_data.mag_x >> 8u, LSM_data.mag_x,
//					     LSM_data.mag_y >> 8u, LSM_data.mag_y,
//					     LSM_data.mag_z >> 8u, LSM_data.mag_z };
	/* transmit the data */
	MSS_UART_polled_tx
	(
		&g_mss_uart1,
		buff, buffSize
	);
}

void print_data()
{
	printf("Accel X data: %x\n\rAccel Y data: %x\n\rAccel Z data: %x\n\rMag X data: %x\n\rMag Y data: %x\n\rMag Z data: %x\n\n\r",
		   LSM_data.acc_x, LSM_data.acc_y, LSM_data.acc_z,
		   LSM_data.mag_x, LSM_data.mag_y, LSM_data.mag_z);
}
