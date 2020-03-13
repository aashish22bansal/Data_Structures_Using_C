/* CONCEPT: RADIX SORT
 * Program to demonstrate Radix Sort.
 */
#include<stdio.h>
#include<conio.h>
int largest(int arr[],int n)
{
	int large=arr[0],i;
	for(i=0;i<n;i++)
	{
		if(arr[i]>large)
		{
			large=arr[i];
		}
	}
	return large;
}
void radix_sort(int arr[],int n)
{
	int bucket[10][10],bucket_count[10];
	int i,j,k,remainder,NOP=0,divisor=1,large,pass;
	large=largest(arr,n);
	while(large>0)
	{
		NOP++;
		large/=10;
	}
	for(pass=0;pass<NOP;pass++)
	{
		for(i=0;i<10;i++)
		{
			bucket_count[i]=0;
		}
		for(i=0;i<n;i++)
		{
			remainder=(arr[i]/divisor)%10;
			bucket[remainder][bucket_count[remainder]]=arr[i];
			bucket_count[remainder]+=1;
		}
		i=0;
		for(k=0;k<10;k++)
		{
			for(j=0;j<bucket_count[k];j++)
			{
				arr[i]=bucket[k][j];
				i++;
			}
		}
		divisor*=10;
	}
}
int main()
{
	int arr[10],i,n;
	printf("\nEnter the number of Elements in the array: ");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
	{
		printf("Element %d: ",(i+1));
		scanf("%d",&arr[i]);
	}
	radix_sort(arr,n);
	printf("\n\n\nThe sorted array is: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	getch();
}
