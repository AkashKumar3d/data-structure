#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int linckedlisttraveral(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    // memory allocate for the nodes in lincked list in heap;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    //lincked first and second nodes
    head->data = 6;
    head->next = second;

    //lincked second and third nodes
    second->data = 12;
    second->next = third;

    //lincked third and null
    third->data = 18;
    third->next = NULL;


    linckedlisttraveral(head);
    return 0;
}
