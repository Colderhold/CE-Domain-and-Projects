#include<stdio.h>
#include <string.h>

int count;
void string_match(char a[20],char b[20])
{
	int i,j,m,n;
	m = strlen(a);
	n = strlen(b);
	for(i=0;i<=m-n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i+j] != b[j])
			{
				break;
			}
		}
		if(j==n)
		{
			printf("\nPattern found at location %d",i);
			count++;
		}
	}
	printf("\nNumber of occurences is: %d",count); 
}

int main()
{
	int m,n;
	char a[20],b[20];
	printf("\nEnter string 1: ");
	scanf("%s",&a);
	printf("\nEnter string 2: ");
	scanf("%s",&b);
	string_match(a,b);
	return 0;
}
