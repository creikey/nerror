CFLAGS = -Wall -Inerror1/ -g

.PHONY: all clean install

SRC=$(wildcard *.c)
HEADERS=$(wildcard nerror1/*.h)
BUILDDIR=build
EXNAME=nerror
TMPOBJS=$(SRC:.c=.o)
OBJS=$(addprefix $(BUILDDIR)/, $(TMPOBJS))

all: $(OBJS) $(HEADERS)
	$(CC) $(OBJS) $(CFLAGS) -o $(EXNAME)

clean:
	-rm -f $(BUILDDIR)/*.o
	-rm -f $(EXNAME)
	-rm -f lib$(EXNAME).a

lib: all
	ar cr lib$(EXNAME).a $(OBJS)

install: all lib
	sudo install -s nerror /usr/local/bin
	sudo install -m 0644 lib$(EXNAME).a /usr/local/lib
	sudo install -d /usr/local/include/nerror1
	sudo install -m 0644 nerror1/* -t /usr/local/include/nerror1


$(BUILDDIR)/%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@