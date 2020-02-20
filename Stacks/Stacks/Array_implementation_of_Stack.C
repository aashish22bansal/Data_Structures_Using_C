#include<stdio.h>
#include<conio.h>
#define MAX 10
int stack[MAX],top=-1;
void push(int stack[],int val)
{
    if(top==MAX-1)
    {
	printf("\nSTACK OVERFLOW");
    }
    else
    {
	top++;
	stack[top]=val;
	printf("\nElement Added.\n");
	//stack[++top]=val;
    }
}
int pop(int stack[])
{
    int val;
    if(top==-1)
    {
	printf("\nSTACK UNDERFLOW");
	return -1;
    }
    else
    {
	val=stack[top];
	top--;
	return val;
    }
}
void display(int stack[])
{
    int i;
    if(top==-1)
    {
	printf("\nSTACK IS EMPTY.");
    }
    else
    {
	for(i=top;i>=0;i--)
	{
	    printf("\n%d",stack[i]);
	}
    }
}
int peek(int stack[])
{
    if(top==-1)
    {
	printf("\nSTACK IS EMPTY.");
	return -1;
    }
    else
    {
	return stack[top];
    }
}
int main()
{
    int val,option;
    //clrscr();
    do
    {
	printf("\n\t\t\tMAIN MENU\n1. Push\n2. Pop\n3. Peek\n4. Display\nEnter your choice: ");
	scanf("%d",&option);
	switch(option)
	{
	    case 1: printf("\nEnter the Element to be push: ");
		    scanf("%d",&val);
		    push(stack,val);
		    break;
	    case 2: printf("\nPopping Element\n");
		    val=pop(stack);
		    if(val==-1)
		    {
			printf("\nThe value deleted from the stack is: %d",val);
		    }
		    break;
	    case 3: val=peek(stack);
		    if(val!=-1)
		    {
			printf("\nThe value stored at the top of the stack is: %d",val);
		    }
		    break;
	    case 4: printf("\n");
		    display(stack);
		    break;
	}
    }while(option!=5);
    getch();
    return 0;
}
