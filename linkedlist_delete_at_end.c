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
// deletion at beetween
struct node *linkedlist_delete_at_end(struct node *head )
{
    struct node *p = head;
    struct node *q = head->next;
   while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
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
    head = linkedlist_delete_at_end(head);
    linckedlisttraveral(head);
    return 0;
}
