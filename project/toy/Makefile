# makfile configuration

COMMON_OBJECTS  =

CPU             = msp430g2553

CFLAGS          = -mmcu=${CPU} -I../h

LDFLAGS		= -L/opt/ti/msp430_gcc/include



#switch the compiler (for the internal make rules)

CC              = msp430-elf-gcc

AS              = msp430-elf-as



all: blink.elf



#additional rules for files

blink.elf: ${COMMON_OBJECTS} main.o switches.o state_machine.o led.o buzzer.o wdInterruptHandler.o ../lib/libTimer.a

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^



load: blink.elf

	msp430loader.sh blink.elf



clean:

	rm -f *.o *.elf



led.o: led.c led.h



wdInterruptHandler.o: state_machine.h



stateMachines.o: led.h state_machine.h



buzzer.o: buzzer.h buzzer.c



switches.o: switches.h switches.c
