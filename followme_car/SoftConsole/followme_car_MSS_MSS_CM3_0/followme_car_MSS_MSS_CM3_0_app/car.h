#ifndef CAR_H_
#define CAR_H_

#include <inttypes.h>
#include "bool.h"

/**
 * Initializes the car to default speeds (stopped).
 */
void initCar();

/**
 * Stops the car.
 */
void stopCar();

/**
 * Moves the car forward at the specified speed.
 */
void moveCarForward(int speed);

/**
 * Moves the car backward at the specified speed.
 */
void moveCarReverse(int speed);

/**
 * Rotates the car clockwise at the specified speed.
 */
void rotateCarRight(int speed);

/**
 * Rotates the car counterclockwise at the specified speed.
 */
void rotateCarLeft(int speed);

/**
 * Turns the car clockwise. The left wheels will move at the
 * specified speed, while the right wheels will move at half
 * the specified speed.
 */
void turnCarRight(int speed);

/**
 * Turns the car counterclockwise. The right wheels will move at the
 * specified speed, while the left wheels will move at half
 * the specified speed.
 */
void turnCarLeft(int speed);

/**
 * Moves the car with specified directions and speeds. Speeds are given
 * as percentage of max speed. Speed of 0 implies stopping the car.
 *
 * @param	leftFwd		Whether the left side should move forward
 * @param	rightFwd	Whether the right side should move forward
 * @param	leftSpeed	Speed of the left side given as a percentage
 * @param	rightSpeed	Speed of the right side given as a percentage
 */
void moveCar(bool leftFwd, bool rightFwd, int leftSpeed, int rightSpeed);

#endif /* CAR_H_ */
