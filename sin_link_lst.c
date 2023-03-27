#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*create()
{
	int ind;
	struct node*h=(struct node*)malloc(sizeof(struct node));
	struct node*t=NULL;
	printf("\nEnter the data item to the Header:");
	scanf("%d",&h->data);
	h->link=NULL;
	t=h;
	while(1)
	{
		printf("\nDo you want to continue(1:yes, 0:no)");
		scanf("%d",&ind);
		if(ind==0)
			break;
		t->link=(struct node*)malloc(sizeof(struct node));
		t=t->link;
		printf("\nEnter the data item to the new node:");
		scanf("%d",&t->data);
		t->link=NULL;
	}
	return h;
}
void display(struct node *h)
{
	printf("Elements of Single LL: ");
	while(h)
	{
		printf("\t%d",h->data);
		h=h->link;
	}
}
struct node*search(struct node*h,int k)
{
	while(h)
	{
		if(h->data==k)
			break;
		h=h->link;
	}
	return h;
}
struct node*b4head(struct node*h,int k)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=k;
	new->link=h;
	return new;
}
struct node*post_tail(struct node*h,int k)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=k;
	new->link=NULL;
	struct node*t=h;
	while(t)
	{	if(t->link==0)
		{
			t->link=new;
			return h;
		}
		t=t->link;
	}
	return new;
}
struct node*b4_key(struct node*h,int k,int r)
{
	struct node*t,*new;
	if(h->data==r)
	{
		h=b4head(h,k);
		return h;
	}
	t=h;
	while(t->link->data!=r)
		t=t->link;
	new=(struct node*)malloc(sizeof(struct node));
	new->data=k;
	new->link=t->link;
	t->link=new;
	return h;	
}
void post_key(struct node*h,int k)
{
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->data=k;
	new->link=h->link;
	h->link=new;
}
void main()
{
	int ch,key,ind,ii,ref;
	struct node*s=NULL;
	struct node*head=NULL;
	head=create();
	do
	{
		printf("\n1. Display\n2. Search\n3. Insert\n4. Delete\n Enter your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(head==0)
				{
					printf("\nThe list is empty");
					break;
				}
				display(head);
				break;
			case 2:if(head==0)
				{
					printf("\nThe list is empty");
					break;
				}
				printf("\nEnter Search key:");
				scanf("%d",&key);
				s=search(head,key);
				if(s!=0)
					printf("\n%d is found at:%u",key,s);
				else
					printf("\nElement not found");
					break;
			case 3:printf("\nEnter key to be inserted:");
				scanf("%d",&key);
				printf("\nEnter Isertion Type:");
				printf("\n1. Before Head\n2. After Tail\n3. Before given key\n4. After given key\n");
				scanf("%d",&ii);
				switch(ii)
				{
					case 1:head=b4head(head,key);
						break;
					case 2:head=post_tail(head,key);
						break;
					case 3:if(head==0)
						{
							printf("\nThe list is empty");
							break;
						}
						printf("\nEnter a reference key: ");
						scanf("%d",&ref);
						s=search(head,ref);
						if(s==0)
						{
							printf("There is no such reference in the list");
							break;
						}
						head=b4_key(head,key,ref);
						break;
					default:if(head==0)
						{
							printf("\nThe list is empty");
							break;
						}
						printf("\nEnter a reference key: ");
						scanf("%d",&ref);
						s=search(head,ref);
						if(s==0)
						{
							printf("\nReference not found");
							break;
						}
						post_key(s,key);
				}
				break;
			case 4://display(head);
				break;
		}
		printf("\nDo you want to continue(1:yes, 0:no):");
		scanf("%d",&ind);
	}while(ind);
}
