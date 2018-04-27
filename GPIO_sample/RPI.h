#ifndef _INC_GPIO_H
#define _INC_GPIO_H

#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BCM2708_PERI_BASE	0x20000000
#define GPIO_BASE		\
	(BCM2708_PERI_BASE + 0x200000)
#define BLOCK_SIZE		(4*1024)

#define INP_GPIO(g)		(*(gpio.addr + ((g)/10)) &= ~(7<<(((g)%10)*3)))      // input
#define OUT_GPIO(g)		(*(gpio.addr + ((g)/10)) |=  (1<<(((g)%10)*3)))      // output
#define GPIO_SET		(*(gpio.addr + 7))                                   // set
#define GPIO_CLR		(*(gpio.addr + 10))                                  // clear

struct bcm2835_peripheral {
	unsigned long addr_p;          // 指到實體記憶體位址
	int mem_fd;                    // 開啟/dev/mem的fd
	void *map;                     // memory map的回傳
	volatile unsigned int *addr;   // 指到register的位址 
};

extern struct bcm2835_peripheral gpio;

int map_peripheral(struct bcm2835_peripheral *p);
void unmap_peripheral(struct bcm2835_peripheral *p);

#endif




