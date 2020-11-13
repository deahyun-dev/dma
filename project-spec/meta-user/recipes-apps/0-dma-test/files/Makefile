APP = 0-dma-test

# Add any other object files to this list below
APP_OBJS = 0-dma-test.o

all: build

build: $(APP)

$(APP): $(APP_OBJS)
	$(CC) -o $@ $(APP_OBJS) $(LDFLAGS) $(LDLIBS) -lxil
clean:
	rm -f $(APP) *.o

