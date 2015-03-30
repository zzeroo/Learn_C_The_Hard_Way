PREFIX?=/usr/local
CFLAGS=-g -Wall -I`pkg-config --cflags apr-1` -I`pkg-config --cflags apr-util-1`
LDFLAGS=-l`pkg-config --libs apr-1` -l`pkg-config --libs apr-util-1` -pthread

all: devpkg

devpkg: bstrlib.o db.o shell.o commands.o

install: all
	install -d $(DESTDIR)/$(PREFIX)/bin/
	install devpkg $(DESTDIR)/$(PREFIX)/bin/

clean:
	rm -f *.o
	rm -f devpkg
	rm -f *.dSYM
