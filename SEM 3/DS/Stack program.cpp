#include<stdio.h>
#include<stdlib.h>
int stack[10],n,i,j,ch=0,top=-1;
void push();
void pop();
void display();
int main()
{
	printf("Enter the number of elements in the stack \n");
	scanf("%d",&n);
	printf("\n Choose one from the below options:\n");
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
	while(ch!=4)
	{
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				push();
				break;
			}
			case 2:
			{
				pop();
				break;
			}
			case 3:
			{
				display();
				break;
			}
			case 4:
			{
				printf("Exiting");
				break;
			}
			default:
			{
				printf("Please Enter valid choice");
				break;
			}	
		}
	}
return 0;
}

void push()
{
	int val;
	if(top == n-1)
	{
	    printf("\nOverflow");
    }
	else
	{
		printf("Enter the value:");
		scanf("%d",&val);
		top = top+1;
		stack[top] = val;
	}
}

void pop()
{
	if(top == -1)
	printf("Underflow");
	else
	top = top-1;
}

void display()
{
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
	if(top == -1)
	{
		printf("Stack is empty");
	}
}
