/* MODULE 5 SEARCHING AND SORTING - Data Structures and Algorithms
 * Chspter 14 Data Structures Using C
 * 14.2 Linear Search
 * Write a program to search an element in an array using linear search technique.
 */
#include<stdio.h>
#include<conio.h>

int main()
{
	int arr[100],num,i,n,found=0,pos=-1;
	//clrscr();
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
	for(i=0;i<num;i++)
	{
		if(arr[i]==n)
		{
			found=1;
			pos=i;
			printf("\nThe element %d is found at position %d and index %d.",n,i,(i+1));
			break;
		}
	}
	if(found==0)
	{
		printf("\nThe element does not exist in the array.");
	}
	getch();
	return 0;
}
