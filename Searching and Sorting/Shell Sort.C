/* CONCEPT: SHELL SORT
 * Program to demonsrate Shell Sort
 */
#include<stdio.h>
#include<conio.h>
#define MAX 100
int main()
{
	int arr[MAX]={-1};
	int i,j,n,flag=1,gap_size,temp;
	printf("\nEnter the number of elements in the array: ");
	scanf("%d",&n);
	printf("\nEnter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	gap_size=n;
	while(flag==1||gap_size>1)
	{
		flag=0;
		gap_size=(gap_size+1)/2;
		for(i=0;i<(n-gap_size);i++)
		{
			if(arr[i+gap_size]<arr[i])
			{
				temp=arr[i+gap_size];
				arr[i+gap_size]=arr[i];
				arr[i]=temp;
				flag=0;
			}
		}
	}
	printf("\nThe sorted array is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	getch();
	return 0;
}
