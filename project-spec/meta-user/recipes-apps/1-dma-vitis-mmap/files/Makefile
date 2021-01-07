APP = 1-dma-vitis-mmap

# INC =  -I/home/daehyun/7_zed_dma_driver_1028/Xlinx_includes/include/
CFLAGS += -I/home/daehyun/7_zed_dma_driver_1028/Xlinx_includes/include/ -MMD
CFLAGS += -I/home/daehyun/7_zed_dma_driver_1028/project-spec/meta-user/recipes-apps/1-dma-vitis-mmap/files/ -MMD

# Add any other object files to this list below
APP_OBJS = 1-dma-vitis-mmap.o
APP_OBJS += xaxidma_bd.o
APP_OBJS += xaxidma_bdring.o
APP_OBJS += xaxidma_g.o
APP_OBJS += xaxidma_selftest.o
APP_OBJS += xaxidma_sinit.o
APP_OBJS += xaxidma.o
APP_OBJS += xaxidma_hw.o
APP_OBJS += xil_cache.o
APP_OBJS += xil_assert.o

DEPS = $(APP_OBJS:.o=.d)
# dummy lines for rebuild oe_runmake
BLT = dh_v_2

all: build

build: $(APP)

$(APP): $(APP_OBJS)
	$(CC) -o $@ $(APP_OBJS) $(LDFLAGS) $(LDLIBS) $(CFLAGS) -lm
clean:
	rm -f $(APP) *.o

-include $(DEPS)
