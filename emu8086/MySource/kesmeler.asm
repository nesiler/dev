.MODEL SMALL
.DATA

msg db "Merhaba Arkadaslar! $"

.CODE

main proc far
    
mov ax , @data
mov ds , ax 

mov dx , offset msg
mov ah, 9
int 21H

mov ah , 4CH
int 21h

main endp
 

