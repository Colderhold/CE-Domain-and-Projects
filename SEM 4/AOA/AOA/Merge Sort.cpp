# include <stdio.h>

int noc=0;
void accept(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter a number ");
		scanf("%d",&a[i]);
	}
}

void merge(int a[], int beg, int mid, int end)
{
	int i = beg;
	int j = mid+1;
	int k = beg;
	int temp[10],t;
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			i++;
			k++;
		}
		else{
			temp[k]=a[j];
			j++;
			k++;
		}
		noc++;
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[k]=a[j];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid)
		{
			temp[k]=a[i];
			i++;
			k++;
		}
	}
	for(t=beg;t<k;t++)
	{
		a[t]=temp[t];
	}
}

void merge_sort(int a[], int beg, int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		merge_sort(a,beg,mid);
		merge_sort(a,mid+1,end);
		merge(a,beg,mid,end);
		noc++;
	}
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
	int a[10],n;
	printf("Enter Number of Elements ");
	scanf("%d",&n);
	accept(a,n);
	merge_sort(a,0,n-1);
	printf("No of comparisions is: %d\n",noc);
	display(a,n);
	return 0;
}
