include ./plateform.mk
include ./mysql.mk

CC=gcc -D_GNU_SOURCE
RM=rm -f

LIBJS_DIR=../deps/js/src
LIBJS_INCLUDE=$(LIBJS_DIR)/dist/include/
LIBJS_LIBNAME=libjs_static.a
LIBJS_LIB=$(LIBJS_DIR)/$(LIBJS_LIBNAME)

all: modules

$(LIBJS_LIB): 
	$(MAKE) -C $(LIBJS_DIR) 


ifeq ($(HAS_MYSQL), yes)
MYSQL_FLAGS=-L./deps/mysac/ -I./deps/mysac/ -lmysac -lmysqlclient_r
MYSQL_DEPS=mysaclib
endif

ifdef DARWIN_BUILD

modules: libape-spidermonkey.c $(LIBJS_LIB) Makefile $(MYSQL_DEPS)
	$(CC) -Wall -g -bundle -undefined suppress -flat_namespace -o lib/libmod_spidermonkey.so libape-spidermonkey.c -I$(LIBJS_INCLUDE) -L$(LIBJS_DIR) -ljs_static -lstdc++ $(MYSQL_FLAGS)

endif
ifdef LINUX_BUILD

CFLAGS = -Wall -O2 -shared -fPIC -rdynamic

modules: libmod_spidermonkey.so

libmod_spidermonkey.so: libape-spidermonkey.c $(LIBJS_LIB) Makefile $(MYSQL_DEPS)
	$(CC) $(CFLAGS) -Wl,-soname,libmod_spidermonkey.so -o lib/libmod_spidermonkey.so libape-spidermonkey.c -I$(LIBJS_INCLUDE) -L$(LIBJS_DIR) -ljs_static -lstdc++ $(MYSQL_FLAGS)
	

endif

clean:
	$(RM) libmod_spidermonkey.so
	$(MAKE) -C $(LIBJS_DIR) clean

mysaclib:
	$(MAKE) -C deps/mysac
