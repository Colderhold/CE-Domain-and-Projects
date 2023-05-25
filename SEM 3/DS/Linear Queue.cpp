#include <stdio.h>
#include <stdlib.h>
#define max 5

int queue[max];
int front=-1,rear=-1;
void insert();
int delete_val();
int peek();
void display();

int main()
{
   	int ch,val;
   		printf("***** Linear Queue *****\n");
		printf("\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit\n");
	do
	{
	   printf("\nEnter your choice: ");
        scanf("%d",&ch);
		switch(ch)
  	{
   		case 1:
   			insert();		
            break;
   		case 2:
   			val=delete_val();
   			if(val!=-1)
		    printf("Elements to be deleted: %d",val);
		    break;
		case 3:
		    val=peek();
		    if(val!=-1)
		    printf("Peek Element is : %d",val);
		    break;
		 case 4:
		    display();
		    break; 
	}
}while(ch!=5);
	   return 0;
}

void insert()
{ 
    int num;
    printf("Enter elements to be inserted: ");
    scanf("%d",&num);
    if(rear==max-1)
    printf("OVERFLOW\n");
    else if(front==-1 && rear==-1)
    {
    front=rear=0;
    queue[rear]=num;
    }
	else
    {
    	queue[++rear]=num;
	}
}

int delete_val()
{
 	int val;
 	if(front==-1 || front>rear)
 	{
 		printf("UNDERFLOW\n");
 		return -1;
	 }
	 else
	 
{
	 	val=queue[front];
	 	front++;
	 	if(front>rear)
	 	front=rear=-1;
	 	return val;
	 }
}
  
  int peek()
  {
  	if(front==-1 || front>rear)
  	{
  		printf("UNDERFLOW\n");
  		return -1;
	  }
	  else
	  {
	  	return queue[front];
	  }
  }
  
  void display()
{
   	int i;
   	if(front==-1 || front>rear)
   	printf("Queue is Empty");
   	else
   	
  		for(i=front;i<=rear;i++)
   		printf("%d \t", queue[i]);   
}
