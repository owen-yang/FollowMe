#include "magnetometer.h"

int main()
{
	enable_LSM();
	while( 1 )
	{
		read_LSM();
		send_over_XBee();
//		for (int i = 0 ; i < 20000; ++i);
	}
}
