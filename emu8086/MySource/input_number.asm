.MODEL SMALL\
.DATA

msg1 db "Kac sayi gircen? $"
msg2 db 0AH , 0DH , "sayi gir: $"
msg3 db "girdin bravo $"


s db 0
t db 0

BOLUM db 0
KALAN db 0

.CODE

main proc far

mov ax , @data
mov ds , ax
mov cx , 0

lea dx , msg1
mov ah , 09H
int 21H

mov ah , 01H
int 21h   

and al , 0FH


mov cl , al
mov bl , al

lea dx , msg2  
mov ah , 09H
int 21h

mov dl , 0

L1:     
    mov ah , 01H
    int 21h
    and al , 0FH
        
    add dl , al
    loop L1
    
mov ax , 0    
mov al , dl
div bl

mov BOLUM , al
mov KALAN , ah   
    
hlt
main endp