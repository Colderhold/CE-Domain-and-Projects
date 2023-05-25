# include<stdio.h>

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

void select_sort(int a[],int n)	
{
	int i,j,min_index,temp,nop=0,noc=0;
	for(i=0;i<n;i++)
	{
		min_index = i;
		for(j=i+1;j<n;j++)
		{
			if(a[min_index]>a[j])
			{
				min_index=j;
			}
			noc++;
		}
		temp=a[i];
		a[i]=a[min_index];
		a[min_index]=temp;
		nop++;
	}
	printf("No. of Comparisions %d \n",noc);
	printf("No. of Passes %d \n",nop);
}

void insert_sort(int a[],int n)	
{
	int i,j,key,nop=0,noc=0;
	for(i=1;i<n;i++)
	{
		key = a[i];
		j = i-1;
	    while(key<a[j] && j>=0)
		{
		    a[j+1]=a[j];
		    j--;
		    noc++;
		}
	    a[j+1]=key;
	    nop++;
	}
	printf("No. of Comparisions %d \n",noc);
	printf("No. of Passes %d \n",nop);
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

void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int a[], int left, int right)
{
	int pivot = left;
	int i = left;
	int j = right;
	while(i<j)
	{
		while(a[i]<a[pivot])
		{
			i++;
		}
		noc++;
		while(a[j]>a[pivot])
		{
			j--;
		}
		noc++;
		swap(&a[i],&a[j]);
	}
	noc++;
	swap(&a[pivot],&a[j]);
	return j;
}

void quick_sort(int a[], int left, int right)
{
	if(left<right)
	{
		int part_point = partition(a,left,right);
		quick_sort(a,left,part_point-1);
		quick_sort(a,part_point+1,right);
	}
	noc++;
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
	int a[10],n,c,d,s;
	printf("Enter Number of Elements ");
	scanf("%d",&n);
	do
	{
	printf("Enter the choice:\n1. Accept Array\n2. Insertion Sort\n3. Selection Sort\n4. Merge Sort\n5. Quick Sort\n6. Display\n7. Binary Search\n");
	scanf("%d",&c);
	switch (c)
	{
		case 1:
			accept(a,n);
	        break;
	    case 2:
	    	insert_sort(a,n);
	    	break;
	    case 3:
	    	select_sort(a,n);
	    	break;
	    case 4:
	    	merge_sort(a,0,n-1);
	        printf("No of comparisions is: %d\n",noc);
	        break;
	    case 5:
	    	quick_sort(a,0,n-1);
	        printf("No of Comparisions is: %d\n",noc);
	        break;
	    case 6:
	    	display(a,n);
	    	break;
	    case 7:
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
	        break;
   }
	printf("\nEnter 1 to continue: ");
	scanf("%d",&d);
	}while(true);
	return 0;
}
