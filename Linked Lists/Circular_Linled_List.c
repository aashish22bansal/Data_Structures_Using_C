/* Data Structures and Algorithms Using C
 * Linked List
 * Write a program to create a circular linked list. Perform insertion and deletion at the beginning and end of the list.
 */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
struct node
{
	int data;
	char name[100];
	struct node *next;
};
struct node *start=NULL;
struct node *create_new_node(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	char naam[100];
	char ans='y';
	while(ans=='y'||ans=='Y')
	{
		printf("\nEnter the integer data[Enter -1 to end]: ");
		scanf("%d",&num);
		printf("\nEnter the string data[Enter -1 to end]: ");
		scanf("%s",naam);
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		strcpy(new_node->name,naam);
		if(start==NULL)
		{
			new_node->next=new_node;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=start;
		}
		printf("\nDo you wish to continue?[Y/N]: ");
		ans=getchar();
	}//END OF WHILE LOOP
	return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		printf("\n%d\t%c",ptr->data,ptr->name);
		ptr=ptr->next;
	}
	printf("\n%d\t%c",ptr->data,ptr->name);
	return start;
}

struct node *insert_beg(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	char naam[100];
	printf("\nEnter the integer data[Enter -1 to end]: ");
	scanf("%d",&num);
	printf("\nEnter the string data[Enter -1 to end]: ");
	gets(naam);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	strcpy(new_node->name,naam);
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	start=new_node;
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *ptr,*new_node;
	int num;
	char naam[100];
	printf("\nEnter the integer data[Enter -1 to end]: ");
	scanf("%d",&num);
	printf("\nEnter the string data[Enter -1 to end]: ");
	gets(naam);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	strcpy(new_node->name,naam);
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	// start=new_node; // THIS IS THE ONLY LINE FROM THE ABOVE CODE WHICH IS NOT PRESENT IN THIS FUNCTION AND THE REST OF THE ENTIRE CODE REMAINS THE SAME
	return start;
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=start->next;
	free(start);
	start=ptr->next;
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=start)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}

struct node *delete_after(struct node *start)
{
	struct node *ptr,*preptr;
	int val;
	printf("\nEnter the value after which the node has to be deleted: ");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	if(ptr==start)
	{
		start=preptr->next;
	}
	free(ptr);
	return start;
}

struct node *delete_list(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		start=delete_end(start);
	}
	free(start);
	return start;
}

int main()
{
	int option;
	//clrscr();
	do
	{
		printf("\n\t\t\tMAIN MENU");
		printf("\n1. Create a list");
		printf("\n2. Display the list");
		printf("\n3. Add a node at the beginning");
		printf("\n4. Add a node at the end");
		printf("\n5. Delete a node from the beginning");
		printf("\n6. Delete a node from the end");
		printf("\n7. Delete a node after a given node");
		printf("\n8. Delete the entire list");
		printf("\n9. EXIT\nEnter your option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: start=create_new_node(start);
					printf("\n\nCircular Linked List created!");
					break;
			case 2: start=display(start);
					break;
			case 3: start=insert_beg(start);
					break;
			case 4: start=insert_end(start);
					break;
			case 5: start=delete_beg(start);
					break;
			case 6: start=delete_end(start);
					break;
			case 7: start=delete_after(start);
					break;
			case 8: start=delete_list(start);
					printf("\n\nCircular Linked List Created");
					break;
		}
	}while(option!=9);
	getch();
	return 0;
}
