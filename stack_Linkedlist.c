
// STACK USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
}*top=NULL;


void push(int x)
{
	struct Node *t;
	t=(struct Node *)malloc(sizeof(struct Node));
	
	if(t==NULL)
	printf("Stack is full");
	else
	{
	    t->data=x;
	    t->next=top;
	    top=t;
	}
}

int pop()
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
    printf("Stack is empty");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}

int peek(int pos)
{
    int i;
    struct Node *p=top;
    for(i=0;p!=NULL && i<pos-1;i++)
    {
        p=p->next;
    }
    if(p!=NULL)
    return p->data;
    else
    return -1;
}

void Display()
{
    struct Node *p;
    p=top;
    
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


int stacktop()
{
    if(top)
    return top->data;
    return -1;
}

int isEmpty()
{
    if(top)
    return 1;
    else return 0;
}

int isFull()
{
    struct Node* t;
    t=(struct Node *)malloc(sizeof(struct Node)); //stcak full hole 1
    if(t==NULL)
    return 1;
    free(t);
    return 0;
}

int main()
{
    push(10); //pos5 i=0  |
    push(20); //pos4 i=1  |   
    push(30); //pos3 i=2  |    basically upor theke niche ache, input 10 then 20
    push(40); //pos2 i=3  |
    push(50); //pos1 i=4  V
    
    Display();
// printf("%d\n",pop());
// printf("%d\n",peek(6));
//printf("%d\n",stacktop());
// printf("%d\n",isEmpty());
//printf("%d\n",isFull());
    return 0;
}
