CFLAGS = -Wall -Inerror1/ -g

.PHONY: all clean lib no-main fix-objs generate install uninstall

SRC=$(wildcard *.c)
HEADERS=$(wildcard nerror1/*.h)
BUILDDIR=build
EXNAME=nerror
MAINS=main.o
TMPOBJS=$(SRC:.c=.o)
OBJS=$(addprefix $(BUILDDIR)/, $(TMPOBJS))
MAINOBJS=$(addprefix $(BUILDDIR)/, $(MAINS))
NOMAINOBJS=$(filter-out $(MAINOBJS),$(OBJS))

all: $(OBJS) $(HEADERS)
	$(CC) $(OBJS) $(CFLAGS) -o $(EXNAME).out

clean:
	-rm -f $(BUILDDIR)/*.o
	-rm -f $(EXNAME).out
	-rm -f -r out
	-rm -f lib$(EXNAME).a

lib: all
	ar cr lib$(EXNAME).a $(NOMAINOBJS)

generate: all lib
	mkdir out
	install -s $(EXNAME).out out/$(EXNAME)
	install -d out/lib
	install -m 0644 lib$(EXNAME).a out/lib
	install -d out/include/nerror1
	install -m 0644 nerror1/* -t out/include/nerror1

install: all lib
	sudo install -s $(EXNAME).out /usr/local/bin/$(EXNAME)
	sudo install -m 0644 lib$(EXNAME).a /usr/local/lib
	sudo install -d /usr/local/include/nerror1
	sudo install -m 0644 nerror1/* -t /usr/local/include/nerror1

uninstall:
	sudo rm -f /usr/local/bin/$(EXNAME)
	sudo rm -f /usr/local/lib/lib$(EXNAME).a
	sudo rm -r -f /usr/local/include/nerror1/

$(BUILDDIR)/%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@
