DATA SEGMENT
   A DW 0006
   B DW 0002
   SUM DW ?
   CARRY DB ?
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
    
    START:MOV AX,DATA
    MOV DS,AX 
    MOV AX,A
    ADD AX,B
    JNC SKIP
    INC CARRY
    SKIP:MOV SUM,AX
    MOV AX,4CH
    INT 21H
   
CODE ENDS
END START 