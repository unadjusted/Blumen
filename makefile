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
	-ffreestanding \


CFILES := $(shell find ./ -type f -name '*.c')
OBJ    := $(CFILES:.c=.o)

.PHONY: all clean

all: $(ISO)

$(ISO): $(OBJ)
	$(XISO) $(XISOFLAGS) -o $@

$(BIN): $(OBJ)
	$(CC) $(LDINTERNALFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ)