include config.mk

all: hello

obj: hello.o
	@echo CC    = ${CC}
	@echo LIBs  = ${LIBS}
	@echo FLAGs = ${FLAGS}
	@echo CC -c hello.c LIBs CFLAGs
	@${CC} -c hello.c ${LIBS} ${CFLAGS} > /dev/null

hello: obj
	@echo CC main.c -o $@ hello.o LIBs CFLAGs
	@${CC} main.c -o $@ hello.o ${LIBS} ${CFLAGS} > /dev/null

clean:
	@echo removing *.o hello...
	@rm *.o hello -rf
