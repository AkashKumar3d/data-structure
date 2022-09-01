#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isfull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("queue is overflow :\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isempty(q))
    {
        printf("queue is empty :\n");
        return 1;
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue q;
    q.size = 3;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    //enque  the elements
    enqueue(&q, 11);
    enqueue(&q, 12);
    enqueue(&q, 13);

    //deque the element
    printf("the dequeue value is %d :\n", dequeue(&q));
    printf("the dequeue value is %d :\n", dequeue(&q));
    printf("the dequeue value is %d :\n", dequeue(&q));

    //after deque again  enque the element  
    enqueue(&q, 14);
    enqueue(&q, 15);
    enqueue(&q, 16);

    if (isempty(&q))
    {
        printf("the queue is empty :\n");
    }
    if (isfull(&q))
    {
        printf("the queue is full :\n");
    }
}
