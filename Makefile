CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump


CFLAGS = -I include -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -g
LDFLAGS = -T link.ld -nostdlib -Wl,-Map=$@.map
OBJCOPYFLAGS = -O binary


#source files here
SRC = main.c gpio.c rcc.c nvic.c usart.c fpu.c systick.c morse.c
SRC_ADJUSTED := $(foreach wrd,$(SRC), src/$(wrd))
INCLUDE := include/*

all: load

software.elf: $(SRC_ADJUSTED) $(INCLUDE)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRC_ADJUSTED) -o $@ -lm -lc -lnosys 

software.bin: software.elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@
	
load: software.bin
	st-flash --reset write $< 0x8000000
clean:
	rm -f software.*
