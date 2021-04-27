LIBS = -lSDL2
PROG = myapp
OBJS = main.o src/core.o src/map.o

#-include config.mak
CFLAGS += -I/opt/local/include -g
LDFLAGS += -L/opt/local/lib

all: $(PROG)
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS) $(LIBS)
clean:
	rm -f $(OBJS) $(PROG)

.PHONY: all clean
