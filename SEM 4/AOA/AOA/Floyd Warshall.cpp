# include <stdio.h>
# define INF 99999

//minimum function
int min(int a,int b)
{
	if(a>b)
	{
		return b;
	}
	else{
		return a;
	}
}

floyd_warshall(int G[10][10], int n)
{
	int i,j,k,cost[10][10];
	//processing input matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				cost[i][j]=0;
			}
			else if(G[i][j]==0)
			{
				cost[i][j]=INF;
			}
			else{
				cost[i][j]=G[i][j];
			}
		}
	}
	
	//warshalls algorithm
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
			}
		}
	}
	//print cost matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(cost[i][j]==INF)
			{
				printf("%s",INF);
			}
			else{
				printf("%d\t",cost[i][j]);
			}
		}
		printf("\n");
	}
}

int main()
{
	int n,G[10][10];
	printf("Enter number of vertices in graph\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("Enter value for G[%d][%d]\t",i,j);
			scanf("%d",&G[i][j]);
		}
	}
	floyd_warshall(G,n);
}
