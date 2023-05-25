# include <stdio.h>

void accept(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter a number ");
		scanf("%d",&a[i]);
	}
}

void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

int binary_search(int a[], int low, int high,int s)
{
	int mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(a[mid]==s)
		{
			return mid;
		}
		else if(s<a[mid])
		{
			return binary_search(a,low,mid,s);
		}
		else
		{
			return binary_search(a,mid+1,high,s);
		}
	}
	return -1;
}

void display(int a[],int n)
{
	int i;
	printf("Sorted Elements are: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

int main()
{
	int a[10],n,s;
	printf("Enter Number of Elements ");
	scanf("%d",&n);
	accept(a,n);
	printf("\n Enter the element to be searched:");
	scanf("%d",&s);
	int pos = binary_search(a,0,n-1,s);
	if(pos==-1)
	{
	    printf("Element not found");
	}
	else
	{
		printf("Element found at location %d\n",pos);
	}
	return 0;
}
