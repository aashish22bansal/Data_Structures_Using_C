/* CONCEPT: QUICK SORT
 * Program to sort the data using Quick Sort.
 */
#include<stdio.h>
#include<conio.h>
int partition(int a[],int beg,int end)
{
	int left,right,loc,temp,flag;
	loc=beg;
	left=beg;
	right=end;
	flag=0;
	while(flag!=1)
	{
		while((a[loc]<=a[right])&&(loc!=right))
		{
			right--;
		}
		if(loc==right)
		{
			flag=1;
		}
		else if(a[loc]>a[right])
		{
			temp=a[loc];
			a[loc]=a[right];
			a[right]=temp;
			loc=right;
		}
		if(flag!=1)
		{
			while((a[loc]>=a[left])&&(loc!=left))
			{
				left++;
			}
			if(loc==left)
			{
				flag=1;
			}
			else if(a[loc]<a[left])
			{
				temp=a[loc];
				a[loc]=a[left];
				a[left]=temp;
				loc=left;
			}
		}
	}
	return loc;
}
void quick_sort(int a[],int beg, int end)
{
	int loc;
	if(beg<end)
	{
		loc=partition(a,beg,end);
		quick_sort(a,beg,loc-1);
		quick_sort(a,loc+1,end);
	}
}
int main()
{
	int arr[10],i,n;
	//clrscr();
	printf("Enter the number of elements present in the array: ");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
	{
		printf("\nElement %d: ",(i+1));
		scanf("%d",&arr[i]);
	}
	quick_sort(arr,0,n-1);
	printf("\nThe sorted array is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	getch();
	return 0;
}
