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
// deletion at head
struct node *delete_linkedlist_head(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *four;

    // memory allocate for the nodes in lincked list in heap;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    four = (struct node *)malloc(sizeof(struct node));

    //lincked first and second nodes
    head->data = 3;
    head->next = second;

    //lincked second and third nodes
    second->data = 6;
    second->next = third;

    //lincked third and null
    third->data = 12;
    third->next = four;

    four->data = 18;
    four->next = NULL;

    printf(" the value of befor delete \n ");
    linckedlisttraveral(head);

    printf(" the value of after delete \n ");
    head = delete_linkedlist_head(head);
    linckedlisttraveral(head);
    return 0;
}
