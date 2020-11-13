APP = dma-test-0

# INC = home/daehyun/7_zed_dma_driver_1028/build/tmp/work-shared/zynq-generic/kernel-source/include
# CFLAGS += -I/home/daehyun/7_zed_dma_driver_1028/build/tmp/work-shared/zynq-generic/kernel-source/include

# Add any other object files to this list below
APP_OBJS = dma-proxy-test.o
APP_OBJS += dma-proxy.o

all: build

build: $(APP)

$(APP): $(APP_OBJS)
	$(CC) -o $@ $(APP_OBJS) $(LDFLAGS) $(LDLIBS) -lxil 
clean:
	rm -f $(APP) *.o

