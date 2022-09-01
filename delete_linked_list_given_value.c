#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void Linked_List_Transversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//inset at a begining ;
struct node *linkedlist_delete__givenvalue(struct node *head, int value)
{

    struct node *p = head;
    struct node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
        
    }
    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 14;
    head->next = second;

    second->data = 17;
    second->next = third;

    third->data = 21;
    third->next = fourth;

    fourth->data = 45;
    fourth->next = NULL;

    Linked_List_Transversal(head);
    head = linkedlist_delete__givenvalue(head,3 );
    Linked_List_Transversal(head);

    return 0;
}
