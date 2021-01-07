obj-m := dma-l.o

MY_CFLAGS += -g -DDEBUG
ccflags-y += ${MY_CFLAGS}

ccflags-y += -I/home/daehyun/7_zed_dma_driver_1028/Xlinx_includes/include/ -MMD

SRC := $(shell pwd)

BLT = daehyun_v_d_12

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(SRC)

modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=$(SRC) modules_install

clean:
	rm -f *.o *~ core .depend .*.cmd *.ko *.mod.c
	rm -f Module.markers Module.symvers modules.order
	rm -rf .tmp_versions Modules.symvers
