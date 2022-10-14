include 'emu8086.inc'
.MODEL SMALL
.DATA

msg db 0AH , 0DH , "Sembol gir: $"

.code

main proc far
    
mov ax , @data
mov ds , ax

;lea dx , msg
;mov ah , 09H
;int 21h
;
;mov ah , 01H
;int 21h
;
mov cl , 10
mov ch , 0
                                   

L:
    
    gotoxy ch , cl
    putc '*' 
    
    inc ch
    dec cl
    jnz L
    

mov cl , 0
mov ch , 10  
  
L1:
    
    gotoxy ch , cl
    putc '*' 
    
    inc ch
    inc cl
    cmp cl , 10
    jne L1
    
    
mov cl , 20
mov ch , 10
                                   

L2:
    
    gotoxy cl , ch
    putc '*' 
    
    inc ch
    dec cl
    cmp cl , 10
    jne L2
    

mov cl , 10
mov ch , 20  
  
L3:
    
    gotoxy cl , ch
    putc '*' 
    
    dec ch
    dec cl
    jnz L3
    
hlt

main endp