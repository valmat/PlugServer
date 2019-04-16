#CC 	 = clang++
CC 	 = g++

NAME	 = PlugServer

OPT_FLAGS=-O3
#OPT_FLAGS=-g -O0

#compiler flags
CFLAGS	 = -std=c++17 $(OPT_FLAGS) -pthread -pedantic -Wall -Wextra -Wno-unused-parameter -fno-rtti -fno-exceptions -flto


BINFILE  = bin/$(NAME).bin

# path to Libevent source
LEVENTPATH = $(PWD)/../deps/libevent
LEVENTL	   = $(LEVENTPATH)/.libs

INIPATH    = $(PWD)/../deps/IniConfigs
INIL	   = $(INIPATH)/src

INCL = -I$(INIPATH)/include -I$(LEVENTPATH)/include

CP = cp -f
CPR = cp -fR
#CPR = ln -sf
#CP = ln -sf
SRC=`pwd`

VERSION=`git -C .. describe --tags --candidates=1`

all: ${BINFILE}


# PlugServer.h.gch: PlugServer.h
# 	g++ $(CFLAGS) -I. -I$(LEVENTI) -c PlugServer.h -o PlugServer.h.gch

bin/obj/$(NAME).rs.o: $(NAME).cpp
	$(CC) $(NAME).cpp $(CFLAGS) -I. $(INCL) -c -DPLUGSERVER_VERSION="\"${VERSION}\"" -o bin/obj/$(NAME).rs.o

bin/obj/EvLogger.rs.o: evhttp/EvLogger.cpp
	$(CC) evhttp/EvLogger.cpp $(CFLAGS) -I. $(INCL) -c -o bin/obj/EvLogger.rs.o

bin/obj/EvServer.rs.o: evhttp/EvServer.cpp
	$(CC) evhttp/EvServer.cpp $(CFLAGS) -I. $(INCL) -c -o bin/obj/EvServer.rs.o

bin/obj/EvResponse.rs.o: evhttp/EvResponse.cpp
	$(CC) evhttp/EvResponse.cpp $(CFLAGS) -I. $(INCL) -c -o bin/obj/EvResponse.rs.o

bin/obj/EvRequest.rs.o: evhttp/EvRequest.cpp
	$(CC) evhttp/EvRequest.cpp $(CFLAGS) -I. $(INCL) -c -o bin/obj/EvRequest.rs.o

bin/obj/Extend.rs.o: extend/Extend.cpp
	$(CC) extend/Extend.cpp $(CFLAGS) -I. $(INCL) -c -o bin/obj/Extend.rs.o

bin/obj/PlugContainer.rs.o: extend/PlugContainer.cpp
	$(CC) extend/PlugContainer.cpp $(CFLAGS) -I. $(INCL) -c -o bin/obj/PlugContainer.rs.o

bin/obj/Extension.rs.o: extend/Extension.cpp
	$(CC) extend/Extension.cpp $(CFLAGS) -I. $(INCL) -c -o bin/obj/Extension.rs.o

bin/obj/ini.rs.o: ini.cpp
	$(CC) ini.cpp $(CFLAGS) -I. $(INCL) -c -o bin/obj/ini.rs.o

# bin/obj/IniValue.rs.o: iniparse/IniValue.cpp
# 	$(CC) iniparse/IniValue.cpp $(CFLAGS) -I. $(INCL) -c -o bin/obj/IniValue.rs.o


.PHONY: obj
obj: bin/obj/$(NAME).rs.o bin/obj/EvLogger.rs.o bin/obj/EvServer.rs.o \
bin/obj/EvResponse.rs.o bin/obj/EvRequest.rs.o bin/obj/Extend.rs.o \
bin/obj/PlugContainer.rs.o bin/obj/Extension.rs.o bin/obj/ini.rs.o
	@echo "#define PLUGSERVER_VERSION \"${VERSION}\"" > "include/version.h"


#dynamic:
${BINFILE}: obj
	$(CC) bin/obj/*.rs.o $(CFLAGS) -lpthread -levent -liniconfig -ldl -L$(LEVENTL) -L$(INIL) -rdynamic -o ${BINFILE}
	strip ${BINFILE}
	@echo
	@echo "\033[1;36mBuild complite \033[0m"
#	@echo "To start the server run ./bin/$(NAME).bin config.ini"


.PHONY: static
static: obj
	$(CC) bin/obj/*.rs.o $(CFLAGS) $(LEVENTL)/libevent.a $(INIL)/libiniconfig.a -ldl -rdynamic -o ${BINFILE}
	strip ${BINFILE}
	@echo
	@echo "\033[1;34mBuild complite \033[0m"


.PHONY: clean install uninstall uninstall-clean


clean:
	rm -f bin/obj/*.o bin/*.bin *.h.gch

gch:
	g++ $(CFLAGS) -I. -I$(LEVENTI) -c PlugServer.h -o PlugServer.h.gch


install:
	# 	mkdir -p /var/plugserver
	# 	chown nobody /var/plugserver
	# 	$(CP) ${SRC}/bin/PlugServer.bin /usr/local/bin/plugserver
	# 	$(CP) ${SRC}/../init.d/plugserver /etc/init.d/plugserver
	# 	mkdir -p /etc/plugserver
	# 	$(CP) ${SRC}/config.ini /etc/plugserver/config.ini
	# 	mkdir -p /usr/lib/plugserver/plugins
	# 	#
	mkdir -p /usr/include/plugserver
	$(CPR) ${SRC}/include/* /usr/include/plugserver/
	# 	#
	# 	update-rc.d plugserver defaults

# uninstall:
# 	update-rc.d -f plugserver remove
# 	rm -f /usr/local/bin/plugserver
# 	rm -f /etc/init.d/plugserver

uninstall-clean:
	# 	update-rc.d -f plugserver remove
	# 	rm -fR /var/plugserver
	# 	rm -fR /etc/plugserver
	# 	rm -fR /usr/lib/plugserver/plugins
	rm -fR /usr/include/plugserver
	# 	rm -f /etc/init.d/plugserver


