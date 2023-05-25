Data segment
    no1 db 04H
    no2 db 06H
    RESULT db ?
    BORROW db 00H
ends

code segment
    Assume CS:code,DS:data
    
    start:MOV AX,data
    MOV DS,AX 
    
    MOV AL,NO1
    MOV BL,NO2
    SUB AL,BL
    JNC skip
    INC borrow
    skip:MOV Result,AL
    
    MOV AH,4CH
    int 21H
   
code ends
end start