.MODEL SMALL
.DATA

x db 1,2,3,4, 5,6,7,8, 9,10,11,12
lr equ 3
lc equ 4

t db 4 DUP(0H)

S equ 8
.CODE

mov ax , @data
mov ds , ax
mov ax , 0

mov si , 0
mov di , 0
mov cx , lr

L1:
    push cx
    mov cx , lc
    mov di , 0
    
        L2:
            mov al , x[si]
            add t[di] , al
            inc di
            inc si
        loop L2
    
    pop cx
    loop L1

hlt           
    

  



