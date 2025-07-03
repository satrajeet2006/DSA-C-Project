#include <stdio.h>
#include <stdlib.h>

// using ARRAY
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

int isFull(struct queue *q)
{
    return q->rear==q->size-1;
}

int isEmpty(struct queue *q)
{
    return q->front == q->rear;
}

void Create(struct queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int*)malloc(q->size*sizeof(int));
}


void Enqueue(struct queue *q,int x)
{
    if(q->rear==q->size-1)
    printf("Queue overflow");
    
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}


int Dequeue(struct queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    printf("queue is empty");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}


void Display(struct queue q)
{
    int i;
    for(i=q.front+1;i<=q.rear;i++)
    printf("%d",q.Q[i]);
    printf("\n");
}

int main()
{
    struct queue q;
    Create(&q,5);
    
    Enqueue(&q,10);
    Enqueue(&q,20);
    Enqueue(&q,30);
    Enqueue(&q,40);
    Enqueue(&q,50);

Display(q);

printf("%d",Dequeue(&q));

    return 0;
}
