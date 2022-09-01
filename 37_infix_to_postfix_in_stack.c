#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int stacktop(struct stack *sp)
{
    return sp->arr[sp->top];
}
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
        ptr->top --;
        return val;
    }
}

int presidence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
    
        return 2;
    }
    else
    {
        return 0;
    }
}

int isopretor(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char *infix_to_postfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * (sizeof(char)));
    char *postfix = (char *)malloc(strlen(infix + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isopretor(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (presidence(infix[i]) > presidence(stacktop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
            j++;
        }
    }
}
while(!isempty(sp))
{
    postfix[j] = pop(sp);
    j++;
}
postfix[j] = '\0';
return  postfix;
}
int main()
{
    char * infix = "x-y/z-k*m+n";
    printf("postfix is %s\n", infix_to_postfix(infix));

    return 0;
}