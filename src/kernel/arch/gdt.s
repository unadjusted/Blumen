;; From devse.wiki (devse.wiki/x86_64/structures/gdt)
[GLOBAL gdtr_install]
gdtr_install: 
    lgdt [rdi]
    push rbp
    mov rbp, rsp
    push qword 0x10
    push rbp
    pushf
    push .trampoline	
    push qword 0x8
    iretq

.trampoline:
    pop rbp
    mov ax, 0x10

    mov ds, ax
    mov es, ax
    mov ss, ax
    ret
