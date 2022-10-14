.MODEL SMALL

Data SEGMENT
    
        sayi db 01H, 02H, 03H, 04H, 05H
        topla db 0

Data EndS

Code SEGMENT
    
    mov ax, @Data
    mov ds, ax
    
    mov cx, 5
    mov ax, 0      
    mov si, 0
    
    
TPL: add al , sayi[si]
inc si

dec cx
jnz TPL

mov topla , al                   

hlt

Code EndS


