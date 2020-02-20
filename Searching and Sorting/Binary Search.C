/* MODULE 5 SEARCHING AND SORTING - Data Structures and Algorithms
 * Chspter 14 Data Structures Using C
 * 14.3 Binary Search
 * Write a program to search an element in an array using binary search technique.
 */
#include<stdio.h>
#include<conio.h>

int arr[100],num,i,n,beg,end,mid,found=0;

int binary_search(int array[],int size,int value)
{
	int val;
	beg=0,end=size-1;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(arr[mid]==value)
		{
			val=mid;
			//return mid;
		}
		else if(arr[mid]>value)
		{
			end=mid-1;
			val=-1;
		}
		else
		{
			end=mid+1;
			val=-1;
		}
	}
	if(mid)
	{
		return mid;
	}
	else
	{
		return -1;
	}
}
int main()
{
	//clrscr();
	int res;
	printf("\nEnter the number of elements in the array: ");
	scanf("%d",&num);
	printf("\nEnter the elements: \n");
	for(i=0;i<num;i++)
	{
		printf("Element %d: ",(i+1));
		scanf("%d",&arr[i]);
	}
	printf("\nEnter the element that you want to search in the array: ");
	scanf("%d",&n);
	res=binary_search(arr,num,n);
	if(res==-1)
	{
		printf("\nThe element does not exist in the array!");
	}
	else
	{
		printf("\nThe element is found at position %d and index %d.",res,(res+1));
	}
}
