DATA SEGMENT
    A DW 6H
    FACT DW ?
    DATA ENDS
CODE SEGMENT
ASSUME CS:CODE DS:DATA
START:
 MOV AX,DATA
 MOV DS,AX
 MOV CX,A
 MOV AH,00H
 MOV AL,01H
 BACK: MUL CX
 DEC CX
 JNZ BACK
 MOV FACT,AX
 MOV AX,4CH
 INT 21H
 CODE ENDS
 END START