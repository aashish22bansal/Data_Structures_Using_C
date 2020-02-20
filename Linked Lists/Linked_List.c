//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         C:\Users\pukes\AppData\Local\Programs\Python\Python36                                                            //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#define MAX 10

struct node
{
	char data[50];
	struct node *next;
};

struct node *start=NULL;

struct node *create_new_node(struct node *start)
{
	struct node *new_node,*ptr;
	char str[50]="";
	printf("Enter the data[Enter -1 to end]: "); 
	gets(str);
	while(str!=NULL)
	{
		new_node=(struct node *)malloc(sizeof(struct node));
		strcpy(new_node->data,str);
		if(start==NULL)
		{
			new_node->next=NULL;
			start=NULL;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->next=NULL;
		}
		printf("\nEnter the data[Enter -1 to exit]: ");
		gets(str);
	}
	return start;
}
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\t%d",ptr->data);
		ptr=ptr->next;
	}
	return start;
}
struct node *insert_beg(struct node *start)
{
	struct node *new_node,*ptr;
	char str[50];
	printf("\nEnter the data: ");
	gets(str);
	new_node=(struct node *)malloc(sizeof(struct node));
	strcpy(new_node->data,str);
	new_node->next=NULL;
	start=new_node;
	return start;
}
struct node *insert_end(struct node *start)
{
	struct node *new_node,*ptr;
	char str[50];
	printf("\nEnter the data: ");
	gets(str);
	new_node=(struct node *)malloc(sizeof(struct node));
	strcpy(new_node->data,str);
	new_node->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	return start;
}
struct node *insert_before(struct node *start)
{
	struct node *new_node,*ptr,*preptr;
	char str_in[50],str_prev[50],str[100];
	printf("\nEnter the data for the node to be inserted: ");
	gets(str_in);
	printf("\nEnter the data present in the previous node: ");
	scanf(str_prev);
	new_node=(struct node *)malloc(sizeof(struct node));
	strcpy(new_node->data,str);
	new_node->next=NULL;
	ptr=start;
	while(strcmp(ptr->data,str_prev)!=0)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}
struct node *insert_after(struct node *start)
{
	struct node *ptr,*new_node,*preptr;
	char str_in[50],str_prev[50],str[100];
	printf("\nEnter the data for the insertion node: ");
	gets(str_in);
	printf("\nEnter the data for the node after which the data is supposed to be inserted: ");
	gets(str_prev);
	new_node=(struct node *)malloc(sizeof(struct node));
	strcpy(new_node->data,str);
	new_node->next=NULL;
	ptr=start;
	preptr=ptr;
	while(strcmp(ptr->data,str_prev)!=0)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
	return start;
}

int main()
{
	int choice;
	do
	{
		printf("\n\t\t\tMAIN MENU:\n1. Create New Node\n2. Display the List\n3. Insert Node in the begginning of the list\n4. Insert a node in the end of the list");
		printf("\n5.Insert a node before a particular node\n6. Insert a node after a particular node\n7. Delete a node in the beginning of the list\n8. Delete a ");
		printf("at the end of the list\n9. Exit\nEnter your choice:  ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: create_new_node(start);
					printf("\nLinked List has been created!");
					break;
			case 2: insert_beg(start);
					printf("\nElement has been appended to the linked list.");
					break;
			case 3: insert_end(start);
					printf("\nElement has been added at the end of the list.");
					break;
			case 4: insert_before(start);
					printf("\nElement has been added before the given element.");
					break;
			case 5: insert_after(start);
					printf("\nElement has been added after the desired element in the list.");
					break;
			case 6: delete_node(start);
					printf("\nElement has been deleted from the list.");
					break;
			case 7: delete_end(start);
					printf("\nElement has been deleted from the end of the list.");
					break;
			case 8:
		}//END OF SWITCH
	}while(choice!=9);
	printf("THE END!");
	getch();
	return 0;
}
