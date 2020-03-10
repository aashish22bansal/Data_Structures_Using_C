/* SEARCHING
 * Program to search an element in an array using interpolation search.
 */
#include<stdio.h>
#include<conio.h>
#define MAX 100
int interpolation_search(int a[],int low, int high,int val)
{
	int mid;
	while(low<=high)
	{
		mid=low+(high-low)*((val-a[low])/(a[high]-a[low]));
		if(val==a[mid])
		{
			return mid;
		}
		if(val<a[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return -1;
}
int main()
{
	int arr[MAX],i,n,val,pos;
	clrscr();
	printf("Enter the number of elements present in the array: ");
	sccanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
	{
		printf("\nElement %d: ",(i+1));
		scanf("%d",&arr[i]);
	}
	printf("\n Enter the number which you want to search in the array: ");
	scanf("%d",&num);
	pos=interpolation_search(arr,0,n-1,val);
	if(pos==-1)
	{
		printf("\n%d is not found in the array",val);
	}
	else
	{
		printf("\n%d is found at position %d",val,pos);
	}
	getch();
	return 0;
}
