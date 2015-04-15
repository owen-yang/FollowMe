#include <inttypes.h>
#include "drivers/mss_uart/mss_uart.h"
#include "drivers/mss_i2c/mss_i2c.h"

#define ACCEL_TARGET_ADDRESS 	(0x32 >> 1u)	// 0011001x
#define MAGNET_TARGET_ADDRESS 	(0x3C >> 1u)	// 0011110x

#define LSM_DATA_TOTAL_SIZE	12

typedef struct LSM_data_struct
{
	uint16_t mag_x, mag_y, mag_z;
	uint16_t acc_x, acc_y, acc_z;
} LSM_data_struct;

extern LSM_data_struct LSM_data;

void write8(const uint8_t reg, uint8_t value);
void read_reg(const uint8_t reg, uint8_t *buf, size_t size);
void read_LSM();
void send_over_XBee();
void print_data();
