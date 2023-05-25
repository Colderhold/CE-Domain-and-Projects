Data segment
    no1 db 10H
    no2 db 02H
    RESULT db ?

ends

code segment
    Assume CS:code,DS:data
    
    start:MOV AX,data
    MOV DS,AX 
    
    MOV AL,NO1
    MOV BL,NO2
    MUL BL
    MOV result,AL
    MOV AH,4CH
    int 21H
   
code ends
end start 