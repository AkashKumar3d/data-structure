#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        printf(" stack is over flow cannot be store the value %d\n:", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf(" stack  is empty \n:");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return val;
    }
}
 int peek(struct stack *sp,int i){
     int arrayind=sp->top-i+1;
     if(arrayind<0){
         printf("not valid position of stack :\n");
     }else{
        return sp->arr[arrayind];
     }
 }
 int stacktop(struct stack * sp){
     return sp->arr[sp->top];
 }

 int stackbottom(struct stack * sp){
     return sp->arr[0];
 }
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 6;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size*sizeof(int));
    // printf("my array create is sucessfully like a empty container \n");

    printf("befour push full: %d\n", isempty(sp));
    printf("befour  puss empty :%d\n", isfull(sp));
    push(sp, 11);
    push(sp, 12);
    push(sp, 13);
    push(sp, 14);
    push(sp, 15);
    push(sp, 16); // stack is overflow
    push(sp, 17); //17 are not store in the stock
    
    printf("the most top value of satck is :%d\n",stacktop(sp));
    printf("the most bottom value of satck is :%d\n",stackbottom(sp));
/*for (int j = 1; j <=sp->top+1; j++)
{
   printf("the peek position %d is %d\n",j,peek(sp,j));
}*/

    return 0;
}