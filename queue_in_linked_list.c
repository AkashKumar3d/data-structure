#include <stdio.h>
#include <stdlib.h>

//gobal decleare the *f and *r;
struct node *f = NULL;
struct node *r = NULL;
struct node
{
    int data;
    struct node *next;
};

int traversal_linked_list(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("queue elements is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("queue is full:\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("queue is empty :\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        return val;
    }
}
int main()
{
    printf("enqueue value is :\n");
    enqueue(11);
    enqueue(12);
    enqueue(13);
    enqueue(14);
    traversal_linked_list(f);

    printf("  dequeue value is :\n");
    printf("dequeue value is:%d\n", dequeue());
    printf("dequeue value is:%d\n", dequeue());
    printf("dequeue value is:%d\n", dequeue());
    printf("dequeue value is:%d\n", dequeue());

    return 0;
}