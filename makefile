# Copyright 2019, 2020, 2021 mintsuki and contributors.

BIN := bin/iso/blumen.bin
ISO := bin/blumen.iso
ROOT := bin/iso
LIMINE := limine-cd.bin

CC = x86_64-elf-gcc
XISO = xorriso


CFLAGS = -Wall -Wextra -O2 -pipe -ansi -ffreestanding
XISOFLAGS = -as mkisofs -b $(LIMINE) -no-emul-boot -boot-load-size 4 -boot-info-table $(ROOT)

LDINTERNALFLAGS := \
	-T src/linker.ld    \
	-nostdlib      \
	-shared        \
	-pie -fno-pic -fpie \
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


CFILES := $(shell find ./ -type f -name '*.c')
OBJ    := $(CFILES:.c=.o)

.PHONY: all clean bin

all: $(ISO)

$(ISO): $(BIN)
	$(XISO) $(XISOFLAGS) -o $@

$(BIN): $(OBJ)
	$(CC) $(LDINTERNALFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INTERNALCFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ) $(ISO)