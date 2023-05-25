# include <stdio.h>

int i,w,k,n,W,P[10],wt[10],v[10][10];
int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void knapsack()
{
	for(i=0;i<=n;i++)
	{
		v[i][0] = 0;
	}
	for(w=0;w<=W;w++)
	{
		v[0][w] = 0;
	}
	for(i=1;i<=n;i++)
	{
		for(w=1;w<=W;w++)
		{
			if(wt[i-1]<=w)
			{
				v[i][w] = max(v[i-1][w],v[i-1][w-wt[i-1]]+P[i-1]);
			}
			else
			{
				v[i][w] = v[i-1][w];
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			printf(" %d ",v[i][w]);
		}
		printf("\n");
	}
	i=n;
	k=W;
	while(i>0 && k>0)
	{
	    if(v[i][k] != v[i-1][k])
	    {
	        printf("\n Item %d added in knapsack",i);
	        i--;
	        k = k-wt[i-1];
	    }
	    else{
	        i--;
	    }
	}
}

int main()
{
	printf("Enter number of items ");
	scanf("%d",&n);
	printf("\nEnter weights\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&wt[i]);
	}
	printf("\nEnter profits\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&P[i]);
	}
	printf("\nEnter capacity of Knapsack ");
	scanf("%d",&W);
	knapsack();
}
