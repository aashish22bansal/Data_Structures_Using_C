/* SUBJECT: Data Structures and Algorithms
 * Chapter 7 Stacks Module 1
 * 7.7.4 Recursion->Tower of Hanoi
 * Self-made Code: Program to get the method to solve the puzzle of Tower of Hanoi.
 */
#include<stdio.h>
#include<conio.h>
//using namespace std;
//tower of HANOI function implementation
void Tower_Of_Hanoi(int n,char Source, char Auxiliary,char Destination)
{ 
	if(n==1)
	{
		printf("Move Disk %d from %c to %c\n",n,Source,Destination);
		return ;
	}
	Tower_Of_Hanoi(n-1,Source,Destination,Auxiliary);
	printf("Move Disk %d from %c to %c\n",n,Source,Destination);
	Tower_Of_Hanoi(n-1,Auxiliary,Source,Destination);
}

//main program
int main()
{ 
	int n;
	//clrscr();
	printf("Enter no. of disks: ");
	scanf("%d",&n);
	//calling the TOH 
	Tower_Of_Hanoi(n,'A','B','C');
	getch();
	return 0;
}
