#include<stdio.h>
#include<conio.h>
//#include<exit.h>
#define MAX 10
int stack[MAX],topA=-1,topB=MAX;
void pushA(int val)
{
    if(topA==topB-1)
    {
	printf("\nOVERFLOW");
    }
    else
    {
	topA+=1;
	stack[topA]=val;
    }
}
int popA()
{
    int val;
    if(topA==-1)
    {
	printf("\nUNDERFLOW");
	val=-999;
    }
    else
    {
	val=stack[topA];
	topA--;
    }
    return val;
}
void display_stackA()
{
    int i;
    if(topA==-1)
    {
	printf("\nStack is Empty.");
    }
    else
    {
	for(i=topA;i>=0;i--)
	{
	    printf("\t%d",stack[i]);
	}
    }
}
void pushB(int val)
{
    if(topB-1==topA)
    {
	printf("\nOVERFLOW");
    }
    else
    {
	topB-=1;
	stack[topB]=val;
    }
}
int popB()
{
    int val;
    if(topB==MAX)
    {
	printf("\nUNDERFLOW");
	val=-999;
    }
    else
    {
	val=stack[topB];
	topB++;
    }
    return val;
}
void display_stackB()
{
    int i;
    if(topB==MAX)
    {
	printf("\nStack B is Empty");
    }
    else
    {
	for(i=topB;i<MAX;i++)
	{
	    printf("\t%d",stack[i]);
	}
    }
}
int main()
{
    int option,val;
    clrscr();
    do
    {
	printf("\n\t\t\tMAIN MENU\n1. Push in Stack A. \n2. Push in Stack B.");
	printf("\n3. Pop in Stack A. \n4. Pop in Stack B.\n5. Display Stack A.");
	printf("\n6. Display Stack B. \n7. Exit.\n Enter your choice: ");
	scanf("%d",&option);
	switch(option)
	{
	    case 1: printf("Enter the element to push in A: ");
		    scanf("%d",&val);
		    pushA(val);
		    break;
	    case 2: printf("Enter the element to push in B: ");
		    scanf("%d",&val);
		    pushB(val);
		    break;
	    case 3: val=popA();
		    if(val==-999)
		    {
			printf("The value popped from stack A: %d",val);
		    }
		    break;
	    case 4: val=popB();
		    if(val==-999)
		    {
			printf("The value popped from stack B: %d",val);
		    }
		    break;
	    case 5: printf("The contents of the Stack A are: \n");
		    display_stackA();
		    break;
	    case 6: printf("The contents of the Stack B are: \n");
		    display_stackB();
		    break;
	    case 7: exit(0);
	}//end of switch
    }while(option!=7);
    getch();
    return 0;
}
