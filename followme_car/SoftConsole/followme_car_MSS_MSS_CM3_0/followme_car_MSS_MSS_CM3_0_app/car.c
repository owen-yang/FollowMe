#include "car.h"

#define MOTOR_CONTROLLER_ADDR 0x40050000

static const int DUTY_RANGE = 50;
static const int DUTY_MIN = 40;

void initCar() {
	stopCar();
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
