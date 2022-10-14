.MODEL SMALL
.DATA

x db 99,55,11,44,77,22,88,33,66,5,115,2
lx equ $-x

min db ?
max db ?

H db ?
B db ?

.CODE

main proc far
    
    mov ax , @data
    mov ds , ax
    mov ax , 0
    
    
    call findmin
    
    call findmax 
    
    hlt
main endp

findmin proc
    
    mov bl , 0
    mov cx , lx
    mov si , 0
    mov al , x[si]
    
    FOR: mov bl , x[si]
         cmp bl , al
         mov H , bl
         mov B , bl
         jle QWE
         
         MIN_DEVAM:
         inc si
         loop FOR
         
    mov min , al     
    ret  
    
    QWE: mov al , bl
         jmp MIN_DEVAM
         
          
    
findmin endp


findmax proc
    
    mov bl , 0
    mov si , 0
    mov cx , lx
    
    FORR: mov bl , x[si]
          cmp bl , al
          cmp bl , al
          mov H , bl
          mov B , bl
          jg QWEE
          
          MAX_DEVAM:
          inc si
          loop FORR
          
    mov max , al      
    ret  
    
    QWEE: mov al , bl
          jmp MAX_DEVAM
          
    
       
    
findmax endp