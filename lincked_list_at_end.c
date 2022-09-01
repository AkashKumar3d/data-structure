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
//inset at a end ;
struct node *Insert_at_end(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    while ( p->next!=NULL)
    {
        p = p->next;
    }
    ptr->data = data;
     p->next=ptr;
    ptr->next = NULL;
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
    head = Insert_at_end(head, 19);
    Linked_List_Transversal(head);

    return 0;
}