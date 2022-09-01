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
void push(struct stack *ptr, char val)
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

char pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf(" stack  is empty \n:");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return val;
    }
}
int prenthesismatched(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isempty(sp))
            {
                return 0;
            }
        }
    }
    pop(sp);
}
int main()
{
    char *exp = "36)*(3)";
    if (prenthesismatched(exp))
    {
        printf("the  prenthesis is matched \n ");
    }
    else
    {
        printf("the  prenthesis is not matched \n");
    }
    return 0;
}