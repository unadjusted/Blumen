# Copyright 2019, 2020, 2021 mintsuki and contributors.

BIN := bin/iso/blumen.bin
ISO := bin/blumen.iso


CC = x86_64-elf-gcc

CFLAGS = -Wall -Wextra -O2 -pipe -ansi -ffreestanding

LDINTERNALFLAGS := \
	-T src/linker.ld    \
	-nostdlib      \
	-ffreestanding \

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

.PHONY: all clean

all: $(ISO)

$(ISO): $(OBJ)

$(BIN): $(OBJ)
	$(CC) $(LDINTERNALFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INTERNALCFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN) $(OBJ)