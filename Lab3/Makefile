COMMON_OBJECTS =

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h 
LDFLAGS 	= -L/opt/ti/msp430_gcc/include -L../lib 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
all: lxdemo.elf
libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

clean:
	rm -f libLcd.a *.o *.elf *~ *#

lxdemo.elf:  ${COMMON_OBJECTS} buzzer.o p2_interrupt_handler.o led.o stateMachines.o switches.o wdInterruptHandler.o button.s lxdemo.o ../lib/libTimer.a libLcd.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: lxdemo.elf
	msp430loader.sh lxdemo.elf
buzzer.o: buzzer.h

wdInterruptHandler.o:stateMachines.h

stateMachines.o: led.h stateMachines.h

led.o:led.c led.h

lxdemo.o:buzzer.h

drawShape.elf: drawShape.o libLcd.a
	$(CC) $(CFLAGS) $^ -o $@ -lTimer
loadShape: drawShape.elf
	msp430loader.sh $^
