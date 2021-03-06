EXEC=bin/aped

prefix		= /usr/local
bindir		= $(prefix)/bin


SRC=src/entry.c src/sock.c src/hash.c src/handle_http.c src/cmd.c src/users.c src/channel.c src/config.c src/json.c src/json_parser.c src/plugins.c src/http.c src/extend.c src/utils.c src/ticks.c src/base64.c src/pipe.c src/raw.c src/events.c src/event_kqueue.c src/event_epoll.c src/transports.c src/servers.c src/dns.c src/sha1.c src/log.c src/parser.c src/md5.c

CFLAGS = -Wall -O2 -minline-all-stringops -rdynamic -I ./deps/udns-0.0.9/
LFLAGS=-ldl -lm -lpthread
CC=gcc -D_GNU_SOURCE
RM=rm -f
LIBUDNS_DIR=./deps/udns-0.0.9
LIBUDNS_LIBNAME=libudns.a
LIBUDNS=$(LIBUDNS_DIR)/$(LIBUDNS_LIBNAME)


all: aped

$(LIBUDNS):
	$(MAKE) -C $(LIBUDNS_DIR) $(LIBUDNS_LIBNAME)

aped: $(SRC) $(LIBUDNS) Makefile
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC) $(LFLAGS) $(LIBUDNS) -I  $(LIBUDNS_DIR)
install: 
	install -d $(bindir)
	install -m 755 $(EXEC) $(bindir)

uninstall:
	$(RM) $(bindir)/aped

clean:
	$(RM) $(EXEC)
	$(MAKE) -C $(LIBUDNS_DIR) clean