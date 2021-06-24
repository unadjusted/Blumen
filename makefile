# Copyright 2019, 2020, 2021 mintsuki and contributors.

BIN := bin/iso/blumen.bin
ISO := bin/blumen.iso
ROOT := bin/iso
LIMINE := limine-cd.bin

CC = x86_64-elf-gcc
ASM = nasm
XISO = xorriso

ASMFLAGS = -f elf64
CFLAGS = -Wall -Wextra -O3 -pipe -ansi -ffreestanding -g3
XISOFLAGS = -as mkisofs -b $(LIMINE) -no-emul-boot -boot-load-size 4 -boot-info-table $(ROOT)

LDINTERNALFLAGS := \
	-T src/linker.ld    \
	-nostdlib      \
	-shared        \
	-fno-pic  \
	-z max-page-size=0x1000

INTERNALCFLAGS  :=       \
	-I.                  \
	-ffreestanding       \
	-fno-stack-protector \
	-fno-pic -fpie       \
	-mno-80387           \
	-mno-mmx             \
	-mno-3dnow           \
	-mno-sse             \
	-mno-sse2            \
	-mno-red-zone


CFILES := $(shell find ./src -type f -name '*.c')
ASMFILES := $(shell find ./ -type f -name '*.s')
ASMOBJ := $(ASMFILES:.s=.asm.o)
OBJ    := $(CFILES:.c=.o)

.PHONY: all clean bin

all: $(ISO)

$(ISO): $(BIN)
	$(XISO) $(XISOFLAGS) -o $@
%.o: %.c
	$(CC) $(CFLAGS) $(INTERNALCFLAGS) -c $< -o $@
$(BIN): $(OBJ) $(ASMOBJ)
	$(CC) $(LDINTERNALFLAGS) $(OBJ) $(ASMOBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INTERNALCFLAGS) -c $< -o $@

%.asm.o: %.s
	$(ASM) $(ASMFLAGS) $(ASMFILES) -o $@

clean:
	rm -rf $(BIN) $(OBJ) $(ISO) $(ASMOBJ)
