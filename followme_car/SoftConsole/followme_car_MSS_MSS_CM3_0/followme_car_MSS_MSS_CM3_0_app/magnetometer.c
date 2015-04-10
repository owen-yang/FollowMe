#include "magnetometer.h"


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
	if (size > 1) target_addr |= 0x80;


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

	/*
	MSS_I2C_write
		(
			&g_mss_i2c1,
			MAGNET_TARGET_ADDRESS,
			&target_addr,
			sizeof(target_addr),
			MSS_I2C_HOLD_BUS
		);

	MSS_I2C_wait_complete(&g_mss_i2c1, MSS_I2C_NO_TIMEOUT);


	MSS_I2C_read
	(
		&g_mss_i2c1,
		MAGNET_TARGET_ADDRESS,
		buf,
		sizeof(buf),
		MSS_I2C_RELEASE_BUS
	);

	MSS_I2C_wait_complete(&g_mss_i2c1, MSS_I2C_NO_TIMEOUT);
	*/
	// return buf;
}
