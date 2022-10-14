.MODEL SMALL  
.DATA

x db 1,2,3,4,5
toplam db 0

.CODE

mov ax , @data
mov ds , ax

mov si , 0
mov cx , 5
mov al , 0

TPL: add al , x[si]
     inc si
     dec cx
     jnz TPL

mov toplam , al

hlt 

