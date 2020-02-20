/* SUBJECT: Data Structures and Algorithms
 * Chapter 8 Queues Module 2
 * 8.4.1 Circular Queuea
 * Write a program to implement CIrcular Queue.
 */
#include<stdio.h>
#include<conio.h>
#define MAX 10
int queue[MAX];//decalaring and defining a queue as global variable with the maximum elements
int front=-1,rear=-1; // these are the front and rear of the queue from where the elements will be inserted and deleted
void insert()
{
	int num; // variable to store the value of the element temporarily
	printf("\nEnter the number to be inserted in the queue: ");
	scanf("%d",&num);
	if(front==1 && rear==-1) // when the queue is empty
	{
		front=rear=0; // initialising it to the first element
		queue[rear]=num; // assigning value
	}
	else if(rear==MAX-1 && front!=0) // when ONLY ONE MORE element can be added to the queue
	{
		rear=0; // queue has become full
		queue[rear]=num;
	}
	else // normally adding elements to the queue
	{
		rear++;
		queue[rear]=num;
	}
}
int delete_element() // deleting elements from the queue
{
	int val;
	if(front==-1 && rear==-1) // checking if the queue is empty
	{
		printf("\nUNDERFLOW");
		return -1;
	}
	val=queue[front]; // getting the value of the first element if the queue is not empty
	if(front==rear) // when there is only one element in the queue
	{
		front=rear=-1; // queue has become empty
	}
	else
	{//The conditions can be separated as well
		if(front==MAX-1)// last element in the queue
		{
			front=0;
		}
		else // normal removal from the queue
		{
			front++;
		}
	}
	return val; // returning the deleted value from the queue
}
int peek()
{
	if(front==-1 && rear==-1)//checking if queue is empty or not
	{
		printf("\nQUEUE IS EMPTY!");
		return -1;
	}
	else // when queue is not empty, the first element is returned
	{
		return queue[front];
	}
}
void display()
{
	int i;
	printf("\n");
	if(front==-1 && rear==-1)//no element will be displayed when the queue is empty
	{
		printf("\nQUEUE IS EMPTY!");
	}
	else
	{
		if(front<rear)//
		{
			for(i=front;i<=rear;i++)
			{
				printf("\t %d",queue[i]);
			}
		}
		else// if(front>rear)
		{
			for(i=front;i<MAX;i++)
			{
				printf("\t %d",queue[i]);
			}
			for(i=0;i<=rear;i++)
			{
				printf("\t %d",queue[i]);
			}
		}
	}
}
void display_c_queue(int queue[],int front,int rear)
{
	int i=0;
	printf("\nCircular Queue is: \n (Front shown as >>>,Rear shown as <<< AND free space as -)\n");
	if(front==-1)
	{
		return ;//when the queue is empty
	}
	if(rear>=front) 
	{ // CASE WHEN REAR REAR OCCURS BEFORE THE OCCURENCE OF FRONT
		for(i=0;i<front;i++) // GETTING EMPTY SPACES
		{
			printf(" - ");
		}
		printf(">>>"); // GETTING THE FRONT OF THE QUEUE
		for(i=front;i<rear;i++) // INSERTING THE ELEMENTS
		{
			printf("%d <-",queue[i]);
		}
		printf("%d <<<",queue[rear]); // INSERTING THE REAR OF THE QUEUE
	}
	else
	{ // CASE WHEN THE OCCURENCE OF FRONT IS BEFORE THE OCCURENCE OF REAR
		for(i=0;i<rear;i++) // INSERTED THE ELEMENTS 
		{
			printf("%d <- ",queue);
		}
		printf("%d <<<",queue[rear]); // INSERTING THE REAR OF THE QUEUE
		for(;i<front;i++) // INSERTING THE FREE SPACES
		{
			printf(" - ");
		}
		printf(">>>"); // SIGNIFING THE FRONT OF THE QUEUE
		for(i=front;i<MAX;i++) //INSERTING THE ELEMENTS LEFT
		{
			printf("%d <-",queue[i]);
		}
		printf("\t ...wrap around..."); // THIS IS THE TIME WHEN THE WRAP AROUND OF THE ELEMENTS HAPPEN
	}
}
int main()
{
	int option,val;
	//clrscr();
	do
	{
		printf("\n\t\t\tMAIN MENU\n1. Insert an element.\n2. Delete an element.\n3. Peek.\n4. Display the queue.\n5. EXIT.\nEnter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: insert();
					break;
			case 2: val=delete_element();
					if(val!=-1)
					{
						printf("\nThe number deleted is: %d",val);
					}
					break;
			case 3: val=peek();
					if(val!=-1)
					{
						printf("\nThe first value in the queue is: %d",val);
					}
					break;
			case 4: printf("\nDISPLAYING THE QUEUE BY THE METHOD GIVEN IN THE BOOK");
					display();
					printf("\n\n\nDISPLAYING THE QUEUE BY THE METHOD LEARNT IN 12TH");
					display_c_queue(queue,front,rear);
					break;
		}
	}while(option!=5);
	getch();
	return 0;
}
