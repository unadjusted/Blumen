
#Copyright (C) 2020  Paul Freland
#    This file is a part of Blumen OS : you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.

#    This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.
#!/bin/bash
export PATH="$PATH:$HOME/opt/cross/bin"
i686-elf-as ./boot/boot.asm -o 
i686-elf-gcc -c  ./kernel/kernel/kernel.c  -o ../Binary/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -T ./kernel/linker.ld -o ../Binary/BlumenOS.bin -ffreestanding -O2 -nostdlib ../Binary/boot.o ../Binary/kernel.o -lgcc
cp ../Binary/BlumenOS.bin ../Binary/isodir/boot/BlumenOS.bin
grub-mkrescue -o ../Binary/BlumenOS.iso ../Binary/isodir
../Binary/run.sh
