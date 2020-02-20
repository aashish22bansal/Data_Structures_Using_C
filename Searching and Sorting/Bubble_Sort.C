/* MODULE 5 SEARCHING AND SORTING - Data Structures and Algorithms
 * Chspter 14 Data Structures Using C
 * 14.7 Bubble Sort
 * Write a program to enter n numbers in an array. Redisplay the array with elements being sorted in ascending order.
 */
#include<stdio.h>
#include<conio.h>

int main()
{
	int i,n,temp,j,arr[100];
	//clrscr();
	printf("\nEnter the number of elements in the array: ");
	scanf("%d",&n);
	printf("\nEnter the elements: \n");
	for(i=0;i<n;i++)
	{
		printf("Element %d: ",(i+1));
		scanf("%d",&arr[i]);
	}
	printf("\nSorting the array: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\nThe array in sorted order is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	getch();
	return 0;
}
