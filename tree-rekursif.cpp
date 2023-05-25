#include <iostream>
using namespace std;
typedef struct node *address;
struct node {
    int data;
    address right;
    address left;
};

void insert(address *tree, int value) {
    address tmp = NULL;
    if((*tree) == NULL) {
        tmp = new node();
        tmp->left = tmp->right = NULL;
        tmp->data = value;
        *tree = tmp;
    } else if(value < (*tree)->data) {
        insert(&(*tree)->left, value);
    } else if (value > (*tree)->data) {
        insert(&(*tree)->right, value);
    }
}

void inorderTraversal(address tree)
{
    if (tree != NULL)
    {
        inorderTraversal(tree->left);
        cout << tree->data << " ";
        inorderTraversal(tree->right);
    }
}

int main() {
    address root, tmp;
    root = NULL;
    insert(&root, 9);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 17);
    insert(&root, 2);

    inorderTraversal(root);
}