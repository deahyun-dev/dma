# # module name: adc-driver != adc-axi. 모듈이름을 adc-axi로 하면 컴파일러가 무시하고 넘어감.
# obj-m := adc-driver.o

# MY_CFLAGS += -g -DDEBUG
# ccflags-y += ${MY_CFLAGS}

# # bsp include path & my_emul
# # ccflags-y += -I/home/daehyun/ps7_cortexa9_0/include/
# ccflags-y += -I/home/daehyun/6_Bladder_200926/project-spec/meta-user/recipes-apps/0-no-neon-process/files


# # compile with source codes <module name>-y
# adc-driver-y := adc-axi-l.o 


obj-m := dma-vitis-driver.o

MY_CFLAGS += -g -DDEBUG
ccflags-y += ${MY_CFLAGS}

ccflags-y += -I/home/daehyun/7_zed_dma_driver_1028/include 

dma-vitis-driver-y := dma-vitis-l.o xil_assert.o xaxidma_bd.o xaxidma_bdring.o xaxidma.o xaxidma_g.o xaxidma_selftest.o xaxidma_sinit.o xil_cache.o
# functions.o 
# xaxidma_hw.o 

BLT = hyundaep_v_26

SRC := $(shell pwd)

all:
	$(MAKE) -C $(KERNEL_SRC) M=$(SRC)

modules_install:
	$(MAKE) -C $(KERNEL_SRC) M=$(SRC) modules_install

clean:
	rm -f *.o *~ core .depend .*.cmd *.ko *.mod.c
	rm -f Module.markers Module.symvers modules.order
	rm -rf .tmp_versions Modules.symvers
