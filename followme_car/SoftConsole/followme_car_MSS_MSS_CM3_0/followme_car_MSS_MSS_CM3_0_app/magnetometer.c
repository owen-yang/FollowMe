#include "magnetometer.h"

magnetometer_data mag_data;

void write8(const uint8_t reg, uint8_t value)
{
	uint8_t data[] = {reg, value};
	MSS_I2C_write
	(
		&g_mss_i2c1,
		MAGNET_TARGET_ADDRESS,
		data,
		sizeof(data),
		MSS_I2C_RELEASE_BUS
	);

	MSS_I2C_wait_complete(&g_mss_i2c1, MSS_I2C_NO_TIMEOUT);
}

void read_reg(const uint8_t reg, uint8_t *buf, size_t size)
{
	uint8_t target_addr = reg;
	// if (size > 1) target_addr |= 0x80; // sequential


	MSS_I2C_write_read
	(
		&g_mss_i2c1,
		MAGNET_TARGET_ADDRESS,
		&target_addr,
		sizeof(target_addr),
		buf, size,
		MSS_I2C_RELEASE_BUS
	);

	MSS_I2C_wait_complete(&g_mss_i2c1, MSS_I2C_NO_TIMEOUT);
}

void enable_magnetometer()
{
	write8(0x00, 0x10);
	write8(0x01, 0x20);
	write8(0x02, 0x00);
}

void read_magnetometer()
{
	uint8_t desired_reg = 0x03;
	uint8_t buf[] = {0, 0, 0, 0, 0, 0};

	read_reg(desired_reg, buf, sizeof(buf));

	mag_data.x = (int16_t)(buf[1] | ((int16_t)buf[0] << 8));
	mag_data.y = (int16_t)(buf[5] | ((int16_t)buf[4] << 8));
	mag_data.z = (int16_t)(buf[3] | ((int16_t)buf[2] << 8));
}

void send_over_XBee()
{
	uint8_t data[6] = {mag_data.x >> 8u, mag_data.x,
					   mag_data.y >> 8u, mag_data.y,
					   mag_data.z >> 8u, mag_data.z };
	/* transmit the magnet data */
	MSS_UART_polled_tx
	(
		&g_mss_uart1,
		data, // data from magnetometer
		sizeof(data)
	);
}

void print_data()
{
	printf("X data: %x\n\rY data: %x\n\rZ data: %x\n\n\r",
			mag_data.x, mag_data.y, mag_data.z);
}
