obj-m := solidusmodule.o


KERNEL_DIR = /usr/src/linux-headers-$(shell uname -r)


all:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(shell pwd) modules

clean:
	rm -rf *.o *.ko *.mod *.symvers *.order *~
