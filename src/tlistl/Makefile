#Part of tlist (github.com/hussam-a/tlist)
#Authors:
#Hussam A. El-Araby (github.com/hussam-a)

#Project code and configurations are under the GNU GPL license (tlist/LICENSE) 

obj-m += tlistl.o

KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD)
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
