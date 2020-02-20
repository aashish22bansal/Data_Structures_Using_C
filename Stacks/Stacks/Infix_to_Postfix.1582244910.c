#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char st[MAX];
int top=-1;
void infixtoPostfix(char source[], char target[])
{
	int i=0,j=0;
	char temp;
	strcpy(target,"");
	while(source[i]!='\0') // till the end of the expression
	{
		if(source[i]=='(') // when an opening bracket is encountered, push it into the stack and increment the counter position to move to the next charater.
		{ // pushing the elements into the stack until the last element in the stack is encountered.
			push(st,source[i]);
			i++;
		}
		else if(source[i]==')') // when a closing bracket is encountered, popping of the element is supposed to be checked based on the previous elements.
		{
			while((top!=-1)&&(st[top]!='(')) //pop elements till (the top of the stack is not empty) and (the top of the stack is not an opening bracket).
			{
				target[j]=pop(st);
				j++;
			}
			if(top==-1) // when the stack is empty but still there are elements left in the expression for popping after the cloding bracket.
			{
				printf("\nINCORRECT EXPRESSION!");
				//exit(1);
			}
			temp=pop(st); // this is to remove the opening bracket as per the while loop above in this condition.
			i++;
		}
		else if(isdigit(source[i])||isalpha(source[i])) // if the element in the expression is a digit or an alphabet.
		{
			target[j]=source[i];
			i++;
			j++;
		}
		else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%') // if the element is an operator
		{
			while((top!=-1)&&(st[top]!='(')&&(getPriority(st[top])>getPriority(source[i]))) // pop until either the stack becomes empty or a closing bracket is
			{ 																				// encountered or the priority of the element is higher than the previous element.
				target[j]=pop(st);
				j++;
			}
			push(st,source[i]); // push the operator into the stack after checking the priority and the associativity of the previous element
			i++;
		}
		else
		{
			printf("\nINCORRECT ELEMENT IN THE EXPRESSION!");
			exit(1);
		}
	}
	while((top!=-1)&&(st[top]!='(')) // ALL THE LEFT OUT ELEMENTS IN THE STACK MUST BE POPPED INORDER TO COMPLETE THE POSTFIX EXPRESSION
	{
		target[j]=pop(st);
		j++;
	}
	target[j]='\0';
}
int getPriority(char op)
{
	if(op=='/'||op=='*'||op=='%') // all these have same and higher priority than the other operators
	{
		return 1;
	}
	else if(op=='+'||op=='-')
	{
		return 0;
	}
}
void push(char st[],char val)
{
	if(top==MAX-1)
	{
		printf("\nSTACK OVERFLOW!");
	}
	else
	{
		st[++top]=val;
	}
}
char pop(char st[])
{
	char val=' ';
	if(top==-1)
	{
		printf("\nSTACK UNDERFLOW");
	}
	else
	{
		val=st[top];
		top--;
	}
	return val;
}
int main()
{
	char infix[100],postfix[100];
	clrscr();
	printf("\nEnter any infix Expression: ");
	gets(infix);
	strcpy(postfix,"");
	///////////////////////////////
	InfixtoPostfix(infix,postfix);
	///////////////////////////////
	printf("\nThe corresponding Postfix Expression is: ")
	puts(postfix);
	getch();
	return 0;
}
