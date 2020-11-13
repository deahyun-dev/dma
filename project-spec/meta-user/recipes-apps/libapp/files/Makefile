APP = libapp

# Add any other object files to this list below
APP_OBJS = libapp.o

BLT = dh_v_13

all: build

build: $(APP)

$(APP): $(APP_OBJS)
	$(CC) -o $@ $(APP_OBJS) $(LDFLAGS) $(LDLIBS) -lxil -lm
clean:
	rm -f $(APP) *.o

