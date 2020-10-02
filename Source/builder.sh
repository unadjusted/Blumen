#!/bin/bash
export PATH="$PATH:$HOME/opt/cross/bin"
i686-elf-as ./boot/boot.asm -o ../Binary/boot.o
i686-elf-gcc -c  ./kernel/kernel/kernel.c  -o ../Binary/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -T ./kernel/linker.ld -o ../Binary/duckOS.bin -ffreestanding -O2 -nostdlib ../Binary/boot.o ../Binary/kernel.o -lgcc
cp ../Binary/duckOS.bin ../Binary/isodir/boot/BlumenOS.bin
grub-mkrescue -o ../Binary/BlumenOS.iso ../Binary/isodir
../Binary/run.sh
