.MODEL SMALL
.DATA
     
x db 1,2,3,4,5,6,7,8,9 
lx equ $-x  

tt db ?
ct db ? 

.CODE

mov ax , @data
mov ds , ax

mov si , 0
mov ax , 0
mov cx , lx 
inc cx

SORGU: dec cx
       jz SON
       mov al , x[si]
       test al , 01H
       jz CIFT
       jnz TEK
       
SON:       
hlt

TEK: add tt , al
     inc si
     jmp SORGU

CIFT: add ct , al 
      inc si
      jmp SORGU
      



