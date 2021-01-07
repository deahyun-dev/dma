APP = 2-dma-vitis-kernel

CFLAGS += -I/home/daehyun/7_zed_dma_driver_1028/include 

# Add any other object files to this list below
APP_OBJS = 2-dma-vitis-kernel.o

BLT = DH_v_5

all: build

build: $(APP)

$(APP): $(APP_OBJS)
	$(CC) -o $@ $(APP_OBJS) $(LDFLAGS) $(LDLIBS) $(CFLAGS) -lm
clean:
	rm -f $(APP) *.o

