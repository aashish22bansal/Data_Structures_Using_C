/* SUBJECT: Data Structures and Algorithms
 * Chapter 7 Stacks Module 1
 * 7.7.3 Evaluation of Arithmetic Expressions -> Evaluation of a Prefix Expression
 * Example 9: Write a program to evaluate a prefix expression.
 */
#include <stdio.h>
#include<conio.h>
#include <string.h>
int stk[10];
int top=-1;
int push(int val)
{
	if(top==10)
	{
		printf("\nSTACK OVERFLOWED!");
		//exit(1);
	}
	else
	{
		stk[++top]=val;
		printf("\nElement Added!");
	}
}
int pop()
{
	int val;
	if(top==-1)
	{
		printf("\nSTACK UNDERFLOW!");
		//exit(1);
	}
	else
	{
		val=stk[top];
		top--;
	}
	return val;
}
int get_type(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char prefix[10];
	int len,val,i,opr1,opr2,res;
	//clrscr();
	printf("\nEnter the excpression which needs to be evaluated: ");
	gets(prefix);
	len=strlen(prefix);
	for(i=len-1;i>=0;i--)
	{
		switch(get_type(prefix[i]))
		{
			case 0: val=prefix[i]-'0';
					push(val);
					break;
			case 1: opr1=pop();
					opr2=pop();
					switch(prefix[i])
					{
						case '+': res=opr1+opr2;
								  break;
						case '-': res=opr1-opr2;
								  break;
						case '*': res=opr1-opr2;
								  break;
						case '/': if(opr2!=0)
								  {
								  	  res=opr1/opr2;
								  }
								  else
								  {
								  	  res=opr2/opr1;
								  }
								  break;
					}
					push(res);
		}//end of switch
	}
	printf("\nRESULT: %d",stk[0]);
	getch();
	return 0;
}
