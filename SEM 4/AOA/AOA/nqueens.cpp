#include <stdio.h>
#include <stdlib.h>

int place(int k,int i,int X[10])
{
    int j;
    for(j=1;j<=k-1;j++)//j pointing to previously set k-1 queens
    {
        if(X[j]==i || abs(X[j]-i)==abs(j-k))//checking if queens are falling on same diagonal
        {
            return 0;
        }
    }
    return 1;
}

void nqueens(int k,int n,int X[10])
{
    int i,t;
    for(i=1;i<=n;i++)//loop columns 
    {
        if(place(k,i,X)==1)//kth queen can be placed in kth row and ith column
        {
            X[k] = i;
            if(k==n)
            {
            	printf("\n Solution array is: ");
                for(t=1;t<=n;t++)//printing solution array
                {
					printf("%d",X[t]);
                }
            }
            else
            {
                nqueens(k+1,n,X);
            }
        }
    }
}

int main() 
{
    int n,X[10];
    printf("Enter Number of Queens: ");
    scanf("%d",&n);
    nqueens(1,n,X);
    return 0;
}
