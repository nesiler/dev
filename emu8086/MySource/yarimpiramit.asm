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

mov bl , 10
mov cl , 0
mov ch , 0
                                   

L:
    mov ch , 0
    L1:
        gotoxy ch , cl
        putc '*' 
        
        inc ch
        cmp ch , cl
    jle L1
    
    inc cl
    cmp cl , bl
    jne L
  
    
hlt

main endp