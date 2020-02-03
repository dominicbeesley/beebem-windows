
#include "m65x_device.h"


void m65x_device::device_start()
{
	init();
}

void m65x_device::device_reset()
{

	sync = false;
	RNW = true;
}

int bob() {
	return 1;
}



