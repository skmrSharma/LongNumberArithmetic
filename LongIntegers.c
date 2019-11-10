#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
struct Node
{
int info;
struct Node *llink,*rlink;
};
typedef struct Node* node;
node createnode()
{
node t;
t=(node)malloc(sizeof(struct Node));
if(t)
	return t;
printf("createnode:Memory allocation failed");
exit(0);
}
void insertFront(node h,int item)
{
node nn;
nn=createnode();
nn->info=item;
nn->rlink=h->rlink;
nn->llink=h;
h->rlink->llink=nn;
h->rlink=nn;
(h->info)++;
}
void insertRear(node h,int item)
{
node nn;
nn=createnode();
nn->info=item;
nn->rlink=h;
nn->llink=h->llink;
h->llink->rlink=nn;
h->llink=nn;
(h->info)++;
}
void display(node h)
{
node t=h->rlink;
if(!(h->info))
{
printf("Empty list\n");
return;
}
while(t!=h)
{
printf("%d",t->info);
t=t->rlink;
}
printf("\n");
}
int ctoi(char c)
{
	c=c-'0';
	return c;
}
void add(node h1,node h2,node hres)		//expiremental
{
	int large,small;
	node ll,ls;
	if(h1->info > h2->info)
	{
		large=h1->info;
		ll=h1->llink;
		small=h2->info;
		ls=h2->llink;
	}
	else
	{
		large=h2->info;
		ll=h2->llink;
		small=h1->info;
		ls=h1->llink;
	}
	int i,carry=0;
	for(i=1;i<=large;i++)
	{
		int lsinfo=ls->info;
		if(i>small)
			lsinfo=0;
		int sum=(lsinfo+ll->info+carry)%10;
		carry=(lsinfo+ll->info+carry)/10;
		insertFront(hres,sum);
		ls=ls->llink;
		ll=ll->llink;
	}
	if(carry != 0)
		insertFront(hres,carry);
}
void subtract(node hl,node hs,node hres)	//hl is the larger number and hs is the smaller one
{
}
main()
{
	int c,i;
	node header[4];
	for(i=0;i<4;i++)
	{
		header[i]=createnode();
		header[i]->info=0;
		header[i]->llink=header[i]->rlink=header[i];
	}
	for(i=0;i<2;i++)
	{	
		printf("Enter the number-%d\n",i+1);
		while((c=getc(stdin)) != '\n')
		{
			if(!(isdigit(c)))
			{	
				printf("Invalid number\n");
				return 1;
			}
			c=ctoi(c);
			insertRear(header[i],c);
		}
	}
	printf("The numbers are\n");
	display(header[0]);
	display(header[1]);
	printf("The sum of above numbers is\n");
	add(header[0],header[1],header[2]);
	display(header[2]);
}
