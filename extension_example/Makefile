CPP             = g++
LD              = g++
#CPP             = clang++
#LD              = clang++

OPT_FLAG=-O3
#OPT_FLAG=-g -O0

NAME       = simple_plugin

CPP_FLAGS  = -std=c++17 -I. -I"/usr/include/plugserver" -I"/usr/local/include/vlm" -pedantic -Wall -Wextra -fno-rtti -fno-exceptions ${OPT_FLAG} -fPIC -flto -c
LD_FLAGS   = -Wall -std=c++17 ${OPT_FLAG} -shared -flto

RESULT     = $(NAME).so

SOURCES    = $(wildcard *.cpp)
OBJECTS    = $(patsubst %.cpp,obj/%.o,$(SOURCES))

all: ${RESULT}

${RESULT}: ${OBJECTS}
	${LD} ${LD_FLAGS} -o $@ ${OBJECTS}
	strip ${RESULT}

${OBJECTS} : obj/%.o : %.cpp
	${CPP} ${CPP_FLAGS} $< -o $@


.PHONY: clean install uninstall

clean:
	rm -f ${OBJECTS} ${RESULT}

install:
	cp -f ${RESULT} /usr/lib/plugserver/plugins/${RESULT}

uninstall:
	rm -f /usr/lib/plugserver/plugins/${RESULT}

