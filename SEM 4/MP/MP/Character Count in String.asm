DATA SEGMENT
    STRING DB "EXERCISE$"
    MSG DB "ENTER A CHARACTER$"
    MSG1 DB "COUNT IS$"
    COUNT DB 00H
    DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE DS:DATA
START: MOV AX,DATA
       MOV DS,AX
       LEA SI,STRING
       MOV CX,08H
       MOV BL,00H
       LEA DX,MSG
       MOV AL,09H
       INT 21H
       MOV AH,01H
       INT 21H
BACK:  CMP AL,[SI]
       JNZ SKIP
       INC BL
SKIP:  INC SI
       LOOP BACK
       MOV COUNT,BL
       LEA DX,MSG1
       MOV AH,09H
       INT 21H
       MOV DL,COUNT
       ADD DL,30H
       MOV AH,02H
       INT 21H
       MOV AH,4CH
       INT 21H
       CODE ENDS
END START