;; From devse.wiki (devse.wiki/x86_64/structures/gdt) 
	
[GLOBAL gdtr_init]
gdtr_init:
    lgdt [rdi]
    push rbp            
    mov rbp, rsp        
    push qword 0x10
    push rbp            
    pushf              
    push qword 0x8      
    push .trampoline    
    iretq
        
.trampoline:
    pop rbp
    mov ax, 0x10

    mov ds, ax
    mov es, ax
    mov ss, ax
    ret
