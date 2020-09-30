global outb
outb:
    mov al, [esp + 8] ; déplace les données à envoyer dans le registre al
    mov dx, [esp + 4] ; déplace l'adresse du port E/S dans le registre dx 
    out dx, al        ; envoie les données vers le port E/S
    ret 