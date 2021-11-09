#include "cs163_bst.h"
using namespace std;


// ***These are sample wrapper functions
table::~table()
{
     remove_all(root); //call the recursive removal_all private function
}

// This is a wrapper function that will call the recursive count function
int table::count()
{
    //Notice how the returned value from the recursive function is used
    return count(root);
}

// Now it is your turn to write the count function recursively
int table::count (node * root)
{
    if (!root) return 0;
    return 1 + count(root -> right) + count(root -> left);
}


// Start with the wrapper function that calls the recursive function
int table::sum()
{
    //Call the recursive function here:
    return sum(root);

}

// Now it is your turn to write the sum function recursively
int table::sum (node * root)
{
    if (!root) return 0;
    return root -> data + sum(root-> right) + sum(root->left);
}


int table::height()   //simply call the private version of the functions
{
    //Call the recursive function here:
    return height(root);

}

//Now write this function recursively
int table::height (node * root){
   if (!root) return -1;

   int lHeight = height(root -> left);
   int rHeight = height(root -> right);

   if (lHeight > rHeight) return lHeight + 1;
   return rHeight + 1;
}       



int table::remove_all()
{
    //Call the recursive function here:
    return remove_all(root);

}

// Now it is your turn to write the remove_all function recursively
int table::remove_all(node * & root)
{
    if (!root) return 0;
    if (root -> right) remove_all(root -> right);
    if (root -> left) remove_all(root -> left);

    delete root;
    root = nullptr;
    return 1;
}  


int table::copy(const table & to_copy)
{
    //Call the recursive function here:
    return copy(root, to_copy.root);

}

// Now it is your turn to write the copy function recursively
int table::copy(node * & dest_root, node * source_root) 
{
    if (!source_root) return 0;
    dest_root = new node;
    dest_root -> data = source_root -> data;
    
    copy(dest_root -> right, source_root -> right);
    copy(dest_root -> left, source_root -> left);

    return 1;

}  

