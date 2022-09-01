#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node* next;
};

void Linked_List_Transversal(struct Node* ptr){
    while(ptr!=NULL){
       printf("Element: %d\n",ptr->data);
       ptr = ptr->next;
    }
    printf("\n");

}
//inset at a begining ;
struct Node* Insert_at_Beginning(struct Node* head,int data1){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data1;
    ptr->next = head;
    return ptr;
}

int main(){
struct Node* head;
struct Node* second;
struct Node* third;
struct Node* fourth;

head = (struct Node* )malloc(sizeof(struct Node));
second = (struct Node* )malloc(sizeof(struct Node));
third = (struct Node* )malloc(sizeof(struct Node));
fourth = (struct Node* )malloc(sizeof(struct Node));

head->data = 14;
head->next = second;

second->data = 17;
second->next = third;

third->data = 21;
third->next = fourth;

fourth->data = 45;
fourth->next = NULL;

Linked_List_Transversal(head);
head = Insert_at_Beginning(head,19);
Linked_List_Transversal(head);






return 0;
}