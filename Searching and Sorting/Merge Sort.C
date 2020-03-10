/* CONCEPT: MERGER SORT
 * Write a program to sort an array using merge sort.
 */
#include<stdio.h>
#include<conio.h>
void merge(int arr[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,index=beg,temp[10],k;
	while((i<=mid)&&(j<=end))
	{
		if(arr[i]<arr[j])
		{
			temp[index]=arr[i];
			i++;
		}
		else
		{
			temp[index]=arr[j];
			j++;
		}
		index++;
	}
	if(i>mid)
	{
		while(j<=mid)
		{
			temp[index++]=arr[j++];
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index++]=arr[i++];
		}
	}
	for(k=beg;k<index;k++)
	{
		arr[k]=temp[k];
	}
}
void merge_sort(int arr[],int beg, int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		merge_sort(arr,beg,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,beg,mid,end);
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
	merge_sort(arr,0,n-1);
	printf("\nThe sorted array is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	getch();
	return 0;
}
