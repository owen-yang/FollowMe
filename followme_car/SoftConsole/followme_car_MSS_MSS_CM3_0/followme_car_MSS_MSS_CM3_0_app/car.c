#include "car.h"
#include "drivers/CoreUARTapb/core_uart_apb.h"

#define MOTOR_CONTROLLER_ADDR 0x40050000
#define COREUARTAPB0_BASE_ADDR 0xC3000000UL

#define BAUD_VALUE_9600    155

static const int DUTY_RANGE = 50;
static const int DUTY_MIN = 40;

UART_instance_t g_uart;

void initCar() {
	stopCar();
	UART_init(&g_uart, COREUARTAPB0_BASE_ADDR,
	          BAUD_VALUE_9600, (DATA_8_BITS | EVEN_PARITY));
}

void stopCar() {
	moveCar(true, true, 0, 0);
}

void moveCarForward(int speed) {
	moveCar(true, true, speed, speed);
}

void moveCarReverse(int speed) {
	moveCar(false, false, speed, speed);
}

void rotateCarRight(int speed) {
	moveCar(true, false, speed, speed);
}

void rotateCarLeft(int speed) {
	moveCar(false, true, speed, speed);
}

void turnCarRight(int speed) {
	moveCar(true, true, speed, speed / 2);
}

void turnCarLeft(int speed) {
	moveCar(true, true, speed / 2, speed);
}

void moveCar(bool leftFwd, bool rightFwd, int leftSpeed, int rightSpeed) {
	uint32_t *addr = (uint32_t*)MOTOR_CONTROLLER_ADDR;
	uint32_t data = 0;

	int leftDuty = 0;
	int rightDuty = 0;

	if (leftSpeed) {
		leftDuty = leftSpeed * DUTY_RANGE / 100 + DUTY_MIN;		// percentage of duty range, offset by minimum duty cycle
	}
	if (rightSpeed) {
		rightDuty = rightSpeed * DUTY_RANGE / 100 + DUTY_MIN;
	}

	data ^= rightFwd;
	data ^= leftFwd << 1;

	data ^= rightDuty << 2;
	data ^= leftDuty << 9;

	*addr = data;
}

void get_LSM_data(uint8_t *rx_buffer, size_t buff_size) {
	UART_get_rx(&g_uart, rx_buffer, buff_size);
}
