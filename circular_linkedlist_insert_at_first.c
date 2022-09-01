#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
//circuler linked list traversal
int linckedlisttraveral(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("element %d\n", ptr->data);
        ptr = ptr->next;

    } while (ptr != head);
}
// circular linkedlist (insert at first)
struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head->next;
    ptr->data = data;

    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
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
    third->next = head;

    printf("elememt before insert \n");
    linckedlisttraveral(head);

    printf("elememt after insert \n");

    head = insertatfirst(head, 5);
    head = insertatfirst(head, 10);
    head = insertatfirst(head, 25);
    linckedlisttraveral(head);
    return 0;
}
