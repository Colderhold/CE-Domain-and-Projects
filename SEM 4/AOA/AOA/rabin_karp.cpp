#include <stdio.h>
#include <string.h>

void rabin_karp(char a[10],char b[10],int q)
{
	int i,j,m,d=256,n,p=0,t=0,h=1;
	m = strlen(b);
	n = strlen(a);
	//Calculate hashvalue for text and pattern
	for(i=0;i<m;i++)
	{
		p = (d*p + b[i])%q;
		t = (d*t + a[i])%q;
	}
	//Match the characters
	for(i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			for(j=0;j<m;j++)
			{
				if(a[i+j] != b[j])
				break;
			}
			if(j==m)
			{
				printf("\nPattern is found at location: %d",i);
			}
		}
		if(i<n-m)
		{
			t = (d*(t-a[i]*h) + a[i+m]) % q;
			//To avoid negative t
			if(t<0)
			{
				t = t + q;
			}
		}
	}
}

int main()
{
	int m,n;
	char a[20],b[20];
	printf("\nEnter string 1: ");
	scanf("%s",&a);
	printf("\nEnter string 2: ");
	scanf("%s",&b);
	rabin_karp(a,b,10);
	return 0;
}
