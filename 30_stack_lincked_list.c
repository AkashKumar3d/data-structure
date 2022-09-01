#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
int linckedlisttraveral(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int isempty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct node *top)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct node *push(struct node *top, int x)
{

    if (isfull(top))
    {
        printf("stack overflow :\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct node *tp)
{

    if (isempty(tp))
    {
        printf("stack underflow :\n");
        return 1;
    }
    else
    {
        struct node *n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

 
int main()
{
    //struct node *top = NULL;
    top = push(top, 12);
    top = push(top, 13);
    top = push(top, 14);
    top = push(top, 15);
    linckedlisttraveral(top);

    int element = pop(top);
    printf("the pop element is %d\n :", element);
    linckedlisttraveral(top);

    
    return 0;
}
