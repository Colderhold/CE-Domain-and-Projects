Data segment
   dividend dw 10H
   divisor db 02H
   result db ?
   carry db 00H
ends

code segment
    Assume CS:code,DS:data
    
    start:MOV AX,data
    MOV DS,AX 
    
    MOV AX,dividend
    MOV BL,divisor
    DIV BL
    JNC skip
    INC carry
    skip:MOV result,AL
    MOV AH,4CH
    int 21H
   
code ends
end start 