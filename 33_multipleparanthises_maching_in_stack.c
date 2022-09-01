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
int matched(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }

    if (a == '{' && b == '}')
    {
        return 1;
    }

    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}
// push the element in the stack
void push(struct stack *ptr, char val)
{
    if (isfull(ptr))
    {
        printf("the stack is full it can not store the value %d\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
//pop the value from stack
char pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("stack is empty :");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return val;
    }
}

int paranthesismatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char poped_ch;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isempty(sp))
            {
                return 0;
            }
            poped_ch = pop(sp);
            if (!matched(poped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isempty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "[2+4]*{6+5}{+(3*6)";
    if (paranthesismatch(exp))
    {
        printf("  the paranthesis is matched :\n");
    }
    else
    {
        printf("the paranthesis is not matched :\n");
    }
    return 0;
}
