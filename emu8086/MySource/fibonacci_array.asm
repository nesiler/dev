.MODEL SMALL

.DATA

dizi db 10 DUP(0H)
sayi equ 10

.CODE

mov ax , @Data
mov ds , ax

mov cx , sayi

mov al , 0
mov ah , 1
mov bl , 0
mov si , 0

FIB: mov bl , ah
     add ah , al
     mov al , bl
     
     mov dizi[si] , ah
     inc si
     dec cx
     jnz FIB
     
hlt