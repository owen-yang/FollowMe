#include "bool.h"

#include "car.h"

int main()
{
	initCar();

	// CAR DEMO

	int count = 0;
	int cycle = 0;
	while( 1 )
	{
		if (count++ >= 2000000) {
			cycle++;
			count = 0;
		}

		switch (cycle) {
		case 0:
			moveCarForward(50);
			break;
		case 1:
			moveCarReverse(50);
			break;
		case 2:
			rotateCarRight(30);
			break;
		case 3:
			rotateCarLeft(30);
			break;
		case 4:
			turnCarRight(40);
			break;
		case 5:
			turnCarLeft(40);
			break;
		case 6:
			stopCar();
			break;
		default:
			cycle = 0;
			break;
		}
	}
}
