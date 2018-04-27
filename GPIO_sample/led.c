#include "RPI.h"

int main()
{
	if (map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space. \n");
		return -1;
	}

	INP_GPIO(4);
	OUT_GPIO(4);

	while (1)
	{
		printf("Led is on...\n");
		GPIO_SET = 1 << 4;
		sleep(1);

		printf("Led is off...\n\n");
		GPIO_CLR = 1 << 4;
		sleep(1);
	}

	return 0;
}
