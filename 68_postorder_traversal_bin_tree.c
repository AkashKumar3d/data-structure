#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create_node(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    struct node *p = create_node(7);
    struct node *p1 = create_node(3);
    struct node *p2 = create_node(1);
    
    p->left = p1;
    p->right = p2;
    postorder(p);
    return 0;
}