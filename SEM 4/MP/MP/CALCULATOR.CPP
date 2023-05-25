#include<stdio.h>
#include<conio.h>
void main()
{
int a,b,c=0,ch,n;
clrscr();
printf("Enter two numbers");
scanf("%d%d",&a,&b);
do{
printf("Enter choice\n1:Addition 2:Subtraction 3:Multiplication 4:Division\n");
scanf("%d",&n);
switch(n)
{
case 1://Addition
asm{
mov ax,a
mov bx,b
add ax,bx
mov c,ax
}break;
case 2://Subtraction
asm{
mov ax,a
mov bx,b
sub ax,bx
mov c,ax
}break;
case 3://Multiplication
asm{
mov ax,a
mov bx,b
mul bx
mov c,ax
}break;
case 4://Division
asm{
mov ax,a
mov bx,b
div bx
mov c,ax
}break;
}
printf("Result is %d\n",c);
printf("Do u want to continue: 1.Yes 2.No");
scanf("%d",&ch);
}while(ch!=0);
getch();
}
