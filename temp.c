#include <stdio.h>
#include <stdlib.h>
struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct circularqueue *q)
{
    if (q->r == q->f) //logic to check the que is empty or not;
    {
        printf("queue is empty:\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct circularqueue *q)
{
    if ( (q->r + 1) % q->size==q->f )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct circularqueue *q, int val)
{
    if (isfull(q))
    {
        printf("queue is overflow:\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size; //logic the input the value of queue;
        q->arr[q->r] = val;
         printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct circularqueue*q)
{
    int val ;
    if (isempty(q))
    {
        printf("queue is empty :\n");
   
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        q->arr[q->f] = val;
        return val;
    }
}
int main()
{
    struct circularqueue q;
    q.size = 3;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

//enque  the elements
    enqueue(&q, 11);
    enqueue(&q, 12);
   
    //deque the element
    printf("the dequeue value is %d :\n", dequeue(&q));
    printf("the dequeue value is %d :\n", dequeue(&q));
   
    //after deque again  enque the element  
    enqueue(&q, 14);
    enqueue(&q, 15);
   
    if (isempty(&q))
    {
        printf("the queue is empty :\n");
    }
    if (isfull(&q))
    {
        printf("the queue is full :\n");
    }
    return 0;

}
