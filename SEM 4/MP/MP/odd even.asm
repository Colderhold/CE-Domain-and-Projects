DISPLAY  MACRO M1     
  LEA DX,M1     
  MOV AH,09H     
  INT 21H
  ENDM DISPLAY  
DATA SEGMENT    
    MSG1 DB 10,13,"ENTER THE NUMBER $"    
    MSG2 DB 10,13, "NUMBER IS EVEN $"     
    MSG3 DB 10,13, "NUMBER IS ODD $"
    DATA ENDS
CODE SEGMENT 
    ASSUME CS:CODE, DS:DATASTART:      
    START: MOV AX,DATA     
    MOV DS,AX     
    DISPLAY MSG1
    MOV AH,01H             
    INT 21H     
    MOV AH,00H              
    MOV DL,02H     
    DIV DL    
    CMP AH,00H    
    JNE ODD    
    EVEN: DISPLAY MSG2      
    JMP EXIT     
    ODD:  DISPLAY MSG3      
    JMP EXIT
    EXIT: MOV AH,4CH      
    INT 21H
    END START 