#include "table.h"

//display in sorted order and return the count
int display_inorder(node * root) {
   if (!root) return 0; //empty tree or at end of path

   //inorder traversal
   int counter = 1;
   counter += display_inorder(root -> left); 
   cout << root -> data << " ";
   counter += display_inorder(root -> right);
   return counter;
}

//postorder - destroy BST
void destroy_all(node *& root) {
    if (!root) return;
    destroy_all(root -> left);
    destroy_all(root -> right);
    delete root;
    root = nullptr;
}
