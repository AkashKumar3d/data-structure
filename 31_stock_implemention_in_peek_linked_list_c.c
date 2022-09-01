#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL; //global  declere for pop use

int linckedlisttraveral(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
// to check my stock is empty or not
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
};

// to check my stock is fullfill or not
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

//to push the the value in stack in decipline
struct node *push(struct node *top, int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (isfull(top))
    {
        printf("stock is overflow");
    }
    else
    {
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct node *t)
{
    if (isempty(t))
    {
        printf("stock is underflow :\n");
    }
    else
    {
        struct node *n = t;
        int x = n->data;
        top = (t)->next;
        free(n);
        return x;
    }
}
int peek(int position){
    struct node *ptr=top;
    for (int i = 0; (i < position-1 && ptr!=NULL); i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;

    }else{
        return -1;
    }
    
}
int main()
{
    //struct node *top = NULL;//without use for pop
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);

    linckedlisttraveral(top);
    //int element = pop(top); //pop function element ;
   // printf("the pop element is %d\n", element);

   for(int i=1;i<=4;i++){
       printf("the value position  at %d is %d\n",i,peek(i));
   }
    //linckedlisttraveral(top);


    return 0;
}