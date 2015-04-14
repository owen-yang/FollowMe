#include <stdio.h>
#include <inttypes.h>
#include "drivers/mss_uart/mss_uart.h"
#include "drivers/mss_i2c/mss_i2c.h"

#define ACCEL_TARGET_ADDRESS 	(0x32 >> 1u)	// 0011001x
#define MAGNET_TARGET_ADDRESS 	(0x3C >> 1u)	// 0011110x

typedef struct magnetometer_data
{
	uint16_t x, y, z;
} magnetometer_data;

extern magnetometer_data mag_data;

void write8(const uint8_t reg, uint8_t value);
void read_reg(const uint8_t reg, uint8_t *buf, size_t size);
void read_magnetometer();
void send_over_XBee();
void print_data();
