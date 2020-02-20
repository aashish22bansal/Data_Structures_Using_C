/* Data Structures and Algorithms Using C
 * Chapter 6 Linked Lists
 * 6.4 Doubly Linked List
 * Example 3
 * Write a program to create a doubly linked list. Perform insertion and deletion in all cases.
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
	struct node *prev;
};

struct node *start=NULL;

struct node *create_new_node(struct node *start)
{
	struct node *new_node,*ptr;
	int num;
	char naam[100];
	printf("\nEnter the numeral data[Enter -1 to end]: ");
	scanf("%d",&num);
	printf("\nEnter the alphnumeric data[Enter -1 to end]: ");
	scanf("%s",naam);
	while( (num!=-1) && (strcmp(naam,-1)==0) )
	{
		if(start==NULL)
		{
			new_node=(struct node *)malloc(sizeof(struct node));
			new_node->prev=NULL;
			new_node->data=num;
			strcpy(new_node->name,naam);
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			new_node=(struct node *)malloc(sizeof(struct node));
			new_node->data=num;
			strcpy(new_node->name,naam);
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->prev=ptr;
			new_node->next=NULL;
		}
		printf("\nEnter the numeral data[Enter -1 to end]: ");
		scanf("%d",&num);
		printf("\nEnter the alphnumeric data[Enter -1 to end]: ");
		scanf("%s",naam);
	}
	return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!NULL)
	{
		printf("\t%d",ptr->data);
		ptr=ptr->next;
	}
	return start;
}

struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	char naam[100];
	printf("\nEnter the numeral data[Enter -1 to end]: ");
	scanf("%d",&num);
	printf("\nEnter the alphanumeric data[Enter -1 to end]: ");
	scanf("%s",naam);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	strcpy(new_node->name,naam);
	start->prev=new_node;
	new_node->next=start;
	new_node->prev=NULL;
	start=new_node;
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *ptr,*new_node;
	int num;
	char naam[100];
	printf("\nEnter the numeral data[Enter -1 to end]: ");
	scanf("%d",&num);
	printf("\nEnter the alphanumeric data[Enter -1 to end]: ");
	scanf("%s",naam);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=NULL;
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
	printf("\nEnter the value after which the node is supposed to be deleted: ");
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
	clrscr();
	do
	{
		printf("\n\t\t\tMAIN MENU");
		printf("\n1. Create a list");
		printf("\n2. Display the list");
		printf("\n3. Add a node at the beginning of the list");
		printf("\n4. Add a node at the end of the list");
		printf("\n5. Delete a node from the beginning of the list");
		printf("\n6. Delete a node from the end of the list");
		printf("\n7. Delete a node after a given node");
		printf("\n8. Delete the entire list");
		printf("\n9. EXIT\nEnter your choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: start=create_new_node(start);
					printf("\nThe Circlar linked list has been created");
					break;
			case 2: start=display(start);
					break;
			case 3: start=insert_beg(start);
					break;
			case 4: start=insert_end(start);
					break;
			case 5: start=delete_beg(start);
					break;
			case 6: start=deletea_end(start);
					break;
			case 7: start=delete_after(start);
					break;
			case 8: start=delete_list(start);
					printf("\nThe entire list has been deleted!");
					break;
		}
	}while(option!=9);
	getch();
	return 0;
}
