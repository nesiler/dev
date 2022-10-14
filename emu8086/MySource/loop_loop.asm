.MODEL SMALL
.DATA

x db 9,8,7,6
lx equ $-x

y db 20,30,40,50
ly equ $-y

z db dup(16)

.CODE

mov ax , @data
mov ds , ax

mov ax , 0
mov si , 0
mov bx , 0
mov cx , lx

L1: mov al , x[si]
    push cx
    
    mov cx , ly
    mov di , 0
    
    L2: mov dl , al
        add dl , y[di]
        mov z[bx] , dl
        inc bx
        inc di
        loop L2
    
    pop cx
    inc si
    loop L1
            

hlt 
     