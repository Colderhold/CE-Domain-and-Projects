# include<stdio.h>
# include<stdlib.h>

int buffer[5],n=5,count=0,in=0,out=0;
int consumer()
{
int item_c;
while(count==0)
{
printf("\nUnderflow Condition\n");
return 0;
}
item_c=buffer[out];
--count;
out++;
printf("\nConsumer consumes %d item\n",out);
}

int producer()
{
int item_p;
while(count==n)
{
printf("\nOverflow Condition\n");
return 0;
}
buffer[in]=item_p;
in++;
printf("\nProducure produces %d item\n",in);
count++;
}

int main()
{
int c;
do{
printf("\n1.Producer\n2.Consumer\n3.Exit\n");
printf("Enter Your Choice\n");
scanf("%d",&c);
switch(c)
{
case 1:
producer();
break;
case 2:
consumer();
break;
case 3:
return 0;
}
}while(c!=3);
return 0;
}
