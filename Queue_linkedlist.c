#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
    printf("Queue is full");
    
    else 
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
        {
            front=rear=t;
        }
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int Dequeue()
{
    int x=-1;
    struct Node *p;
    
    if(front==NULL)
    printf("Queue is empty");
    
    else
    {
        p=front;
        front=front->next;
        x=p->data;
        free(p);
    }
    return x;
}


void Display()
{
    struct Node *p=front;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    
    Display();
    printf("%d\n",Dequeue());
    return 0;
}



