#include "magnetometer.h"

int main()
{
	enable_LSM();
	int count = 0;
	uint32_t *addr = (uint32_t*)0x40050000;

	while(!connection_OK);

	while( 1 )
	{
		// check_status();
		read_LSM();
		send_over_XBee();
		// print_data();

		// flicker an LED to make sure this loop isn't stuck
		if (count++ == 100)
		{
			*addr = 1;
		}
		if (count == 200)
		{
			*addr = 0;
			count = 0;
		}
	}
}
