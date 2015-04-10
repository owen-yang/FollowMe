#include <stdio.h>
#include <inttypes.h>
#include "drivers/mss_i2c/mss_i2c.h"

#define ACCEL_TARGET_ADDRESS 	(0x32 >> 1u)	// 0011001x
#define MAGNET_TARGET_ADDRESS 	(0x3C >> 1u)	// 0011110x

void write8(const uint8_t reg, uint8_t value);
void read_reg(const uint8_t reg, uint8_t *buf, size_t size);

