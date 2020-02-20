#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 10
int top=-1,stack[MAX];
void push(char c)
{
	if(top==(MAX-1))
	{
		printf("Stack Overflow");
	}
	else
	{
		stack[++top]=c;
	}
}
char pop()
{
	if(top==-1)
	{
		printf("\nStack Underflow");
	}
	else
	{
		return(stack[top--]);
	}
}
int main()
{
	char exp[MAX],temp;
	int i,flag=1;
	//clrscr();
	printf("Enter an expression: ");
	gets(exp);
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
		{
			push(exp[i]);
		}
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
		{
			if(top==-1) //when stack is empty and an extra closing bracket is present.
			{
				flag=0;
			}
			else // when the stack is not empty
			{
				temp=pop();
				if((exp[i]==')') && (temp=='{' || temp=='['))
				{
					flag=0;
				}
				if((exp[i]=='}') && (temp=='(' || temp=='['))
				{
					flag=0;
				}
				if((exp[i]==']') && (temp=='{' || temp=='('))
				{
					flag=0;
				}
			}
		}
	}
	if(top>=0)
	{
		flag=0;
	}
	if(flag==1)
	{
		printf("\nValid Expression");
	}
	else
	{
		printf("\nInvalid Expression");
	}
	getch();
	return 0;
}
