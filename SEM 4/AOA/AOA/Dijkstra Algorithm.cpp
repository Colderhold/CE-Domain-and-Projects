# include<stdio.h>

void dijkstra(int G[10][10],int n,int s)
{
	int parent[10],visited[10],distance[10];
	int infinity=999,count,i,j;
	//initialize graph
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
			{
				G[i][j]=infinity;
			}
			else{
				G[i][j]=G[i][j];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		distance[i]=G[s][i];
		visited[i]=0;
		parent[i]=s;
	}
	//initialize single source vertex
	distance[s]=0;
	visited[s]=1;
	count=1;
	//explore next minimum node
	while(count<n-1)
	{
		int min_dis = infinity;
		int next_node;
		for(i=0;i<n;i++)
		{
			if(min_dis > distance[i] && !visited[i])
			{
				min_dis = distance[i];
				next_node = i;
			}
		}
		visited[next_node] = 1;
		//relaxing all adjacent edges
		for(i=0;i<n;i++)
		{
			if(!visited[i])
			{
				if(min_dis+G[next_node][i] < distance[i])
				{
					distance[i] = min_dis + G[next_node][i];
					parent[i] = next_node;
				}
			}
		}
		count++;
		//end of while
	}
	//print distance of shortest path
	for(i=0;i<n;i++)
	{
		printf("\n Distance of vertex is: %d = %d\n",i,distance[i]);
		printf("\n Path of vertex is %d",i);
		j=i;
		do
		{
		    j=parent[j];
			printf("<-- %d",j);
		}while(j!=s);
	}
	//end of function
}

int main()
{
	int i,j,G[10][10],n;
	printf("Enter number of vertices:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter the distance of vertex [%d][%d]: \n",i,j);
			scanf("%d",&G[i][j]);
		}
	}
	dijkstra(G,n,0);
	return 0;
}
