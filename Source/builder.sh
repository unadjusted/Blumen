#!/bin/bash
cd "$HOME/bing/duck OS/Source"
export PATH="$PATH:$HOME/opt/cross/bin"
i686-elf-as ./boot/boot.asm -o ../Binary/boot.o
i686-elf-gcc -c ./kernel/main.c  -o ../Binary/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -T ./boot/linker.ld -o ../Binary/duckOS.bin -ffreestanding -O2 -nostdlib ../Binary/boot.o ../Binary/kernel.o -lgcc
cp ../Binary/duckOS.bin ../Binary/iso/boot/duckOS.bin
grub-mkrescue -o ../Binary/duckOS.iso ../Binary/iso
qemu-system-i386 -cdrom ../Binary/duckOS.iso
