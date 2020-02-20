/* SUBJECT: Data Structures and Algorithms
 * Chapter 8 Queues Module 2
 * Array Representation of Queues
 * Write a program to implement Linear Queue.
 */
#include<stdio.h>
#include<conio.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void insert()
{
	int num;
	printf("\nEnter the number to be inserted in the Queue: ");
	scanf("%d",&num);
	if(rear==MAX-1) //  when you reach the end of the queue
	{
		printf("\nOVERFLOW!");
	}
	else if(front==-1 && rear==-1)// when the queue is empty
	{
		front=rear=0;//getting it to the first element
	}
	else // appending the element normally to the queue
	{
		rear++; // incrementing the count to assign the element
	}
	queue[rear]=num;//assigning the element
}
int delete_element()
{
	int val;
	if(front==-1 || front>rear)//when the queue is empty
	{
		printf("\nUNDERFLOW!");
		return -1; // returning -1 to inform user about the end of the queue
	}
	else
	{
		val=queue[front]; // getting the value because it cannot be left as such so the value is returned from the function and the count of the front is just
		                  // decremented in order to move front.
		front++;
		if(front>rear) // when there is only one element left in the queue
		{
			front=rear=-1; // making the queue empty by removing even the zeroth element from it and getting the count to the initial count.
		}
		return val; // returning the value because it cannot be left as such
	}
}
int peek() //function just to get the value of front in the queue
{
	if(front==-1 || front>rear) // front==-1 means that no element present in the first position and front>rear means that front is ahead to queue and making
	{                           // sure that the queue remains a LINEAR queue and does not become a multiple or circular queue by moving the rear ahead of front.
		printf("\nQUEUE IS EMPTY.");
		return -1; // returing -1 to shoe that the queue is empty.
	}
	else
	{
		return queue[front]; // returning the front of the queue
	}
}
void display()
{
	int i;
	printf("\n");
	if(front==-1 || front>rear) // front==-1 means that no element present in the first position and front>rear means that front is ahead to queue and making
	{                           // sure that the queue remains a LINEAR queue and does not become a multiple or circular queue by moving the rear ahead of front.
		printf("\nQueue is Empty!");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("\t %d",queue[i]);
		}
	}
}
int main()
{
	int option,val;
	//clrscr();
	do
	{
		printf("\n\n\t\t\tMAIN MENU\n1. Insert an element.\n2. Delete an element.\n3. Peek. \n4. Display the queue.\n5. EXIT.\nEnter your choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: insert();
					break;
			case 2: val=delete_element();
					if(val!=-1)
					{
						printf("\nThe element deleted is: %d",val);
					}
					else
					{
						printf("\nNothing in the queue!");
					}
					break;
			case 3: val=peek();
					if(val!=-1)
					{
						printf("\nThe first value in queue is: %d",val);
					}
					break;
			case 4: display();
					break;
		}
	}while(option!=5);
	getch();
	return 0;
}
