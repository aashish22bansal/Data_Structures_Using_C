/* SUBJECT: Data Structures and Algorithms
 * Chapter 7 Stacks Module 1
 * 7.7.4 Recursion
 * Example 10: Program to calculate the factorial of a given number.
 */
#include<stdio.h>
#include<conio.h>
/*inline */int Fact(int n)
{
	if(n==1) // if the number entered is equal to 1.
	{
		return 1;
	}
	else
	{
		return (n*Fact(n-1)); // recurring but still the question in the scope still remains unanswered.
		/* The function overheads need to be checked
		 * How can a function call itself inside it's own code?
		 * If it is an inline function then how is the recurring function placed as the code always gets replaced by the actual code?
		 * Which is more efficient: inline function which will exclude overheads or an inline function which will have larger size as the replaced code does have
		   a penalty of space?
		 * How is a recurring code compiled?
		 */
	}
}
int main()
{
	int num,val;
	printf("\nEnter the number for the calculation of the factorial: ");
	scanf("%d",&num);
	val=Fact(num);
	printf("\nThe factorial of %d is: %d",num,val);
	getch();
	return 0;
}
