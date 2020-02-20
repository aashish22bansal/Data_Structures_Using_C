/* SUBJECT: Data Structures and Algorithms
 * Chapter 7 Stacks Module 1
 * 7.7.4 Recursion->Greatest Common Divisor
 * Example 11: Program to calculate the GCD of two numbers using recursive functions.
 */
#include<stdio.h>
//#include<conio.h>
int GCD(int x,int y)
{
	int rem;
	rem=x%y;
	if(rem==0)
	{
		return y;
	}
	else
	{
		return(GCD(y,rem));
	}
}
void main()
{
	int num1,num2,res;
	printf("\nEnter two numbers: ");
	scanf("%d %d",&num1,&num2);
	res=GCD(num1,num2);
	printf("\nThe GCD of %d and %d is: %d",num1,num2,res);
	//getch();
	//return 0;
}
