ARMGNU = arm-none-eabi

AOPS = --warn --fatal-warnings -mcpu=cortex-m3
COPS = -Wall -Werror -O2 -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0

all : output.hex
clean:
	rm -f *.bin
	rm -f *.o
	rm -f *.elf
	rm -f *.list
	rm -f *.bc
	rm -f *.opt.s
	rm -f *.norm.s
	rm -f *.hex
startup.o : startup.s
	$(ARMGNU)-as $(AOPS) startup.s -o startup.o
programentry.o : programentry.c	
	$(ARMGNU)-gcc $(COPS) -mthumb -mcpu=cortex-m3 -march=armv7-m -c programentry.c -o programentry.o

output.hex : linker.ld startup.o programentry.o
	$(ARMGNU)-ld -o output.elf -T linker.ld startup.o programentry.o
	$(ARMGNU)-objdump -D output.elf > output.list
	$(ARMGNU)-objcopy -O ihex output.elf output.hex
