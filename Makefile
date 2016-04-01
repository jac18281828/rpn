MAJOR=1
VERSION=${MAJOR}.0.0

CC=c++
RM=rm -f

#OPT= -O2
OPT= -g 

CFLAGS=-DRPN_VERSION=\"${VERSION}\" -Iinclude \
	-Wshadow \
	-Wpointer-arith -Wcast-qual -Wcast-align \
	-Wwrite-strings \
	-fno-common \
	${OPT} \
	-ansi -pedantic

LDFLAGS=-ly -ll -lm

OBJS=	\
	rpn.o \
	tokens.o \
	machine.o \
	printerrorhandler.o \
	stringstacktype.o \
	doublestacktype.o \
	main.o 

all: rpn

clean:
	rm -f rpn ${OBJS} tokens.cpp rpn.cpp rpn.hpp

rpn: tokens.cpp rpn.cpp ${OBJS}
	${CC} -o $@ ${OBJS} ${LDFLAGS}

rpn.cpp: rpn.y
	bison -d -o $@ $<

tokens.cpp: tokens.l
	lex -i -o $@ $<

%.o : %.cpp
	${CC} ${CFLAGS} -c $<
