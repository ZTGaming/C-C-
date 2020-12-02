//queeue using linked list
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*ptr,*head,*front,*rear;


int insert(int item)
{
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=item;
	if(front==NULL)
	{
		front=rear=ptr;
		rear->next=NULL;
	}
	else
	{
		rear->next=ptr;
		rear=rear->next;
		rear->next=NULL;
	}
	return 0;
}

void deletez()
{
	ptr=front;
	front=front->next;
	free(ptr);
}

void display()
{
	head=front;
	if((front==NULL)&&(rear==NULL))
	{
		printf("\n QUeue is EmPtY");
	}
	
	
	while(head!=rear)
	{
		printf("\n %d ",head->data);
		head=head->next;
	}
	if(head==rear)
	printf("%d ",head->data);
	
}
int main()
{
	int c,item;
	while(c!=3)
	{
		 printf("\n Enter the choice 1.create 2.display 3.exit 4.delete");
        scanf("%d",&c);

	switch(c)
	{
		case 1: 
		        printf("\n enter an element ");
			scanf("%d",&item);
			insert(item);
			break;
		case 2 :display();
			break;
		case 3: printf("\n EXIT");
			break;
		case 4:printf("\n Elemnet at front end deleted ");
			deletez();
		       break;
		default :printf("\n wrong chocie");
	}
	}
	return 0;
}

