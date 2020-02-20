/* SUBJECT: Data Structures and Algorithms
 * Chapter 8 Queues Module 2
 * 8.5 Applications of Queues
 * Write a program which finds the solution of Josephus problem using a circular linked list.
 */
#include<stdio.h>
#include<conio.h>
#include<malloc.h>// used to allocate memory for a large block of the specified size
struct node
{
	int player_id;
	struct node *next;
}*start,*ptr,*new_node;

int main()
{
	int n,k,i,count;
	//clrscr();
	printf("\nEnter the number of players: ");
	scanf("%d",&n);
	printf("\nEnter the value of k(every kth player gets eliminated): ");
	scanf("%d",&k);
	//create circular linked list containing all the players
	start=malloc(sizeof(struct node));
	start->player_id=1; // pointer to the head of the node.
	ptr=start; // stores the address of the block which contains the data of the block.
	for(i=2;i<=n;i++)
	{
		new_node=malloc(sizeof(struct node)); // same for dynamic memory allocation
		ptr->next=new_node; // pointer to store the address of the newly created block in the previous block
		new_node->player_id=i;// storing the player data in the block
		new_node->next=start;
		ptr=new_node;
	}
	for(count=n;count>1;count--)
	{
		for(i=0;i<k-1;++i)
		{
			ptr=ptr->next;
		}
		ptr->next=ptr->next->next;//remove the eliminated player from the linked list
	}
	printf("\nThe Winner is Player %d",ptr->player_id);
	getch();
	return 0;
}
