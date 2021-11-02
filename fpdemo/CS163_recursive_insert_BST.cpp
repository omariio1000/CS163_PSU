#include "table.h"

//recursive insert ffor a BST

void insert_BST(node * & root, int new_data) {
    if (!root) {//empty or finished traversing
        root = new node;
        root -> data = new_data;
        root -> left = root -> right = nullptr;
        return;
    }
    if (new_data < root -> data) insert_BST(root -> left, new_data);
    else insert_BST(root -> right, new_data);
    return;
}
