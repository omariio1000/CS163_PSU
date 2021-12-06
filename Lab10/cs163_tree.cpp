#include "cs163_tree.h"
using namespace std;



//These are the functions that you will be writing for the BST


void table::display_largest(){
    if (!root) return;
    return display_largest(root);
}      	//STEP 1
void table::display_largest(node * root) {
    if (root -> right) return display_largest(root -> right);
    cout << endl << "Largest value in BST: " << root -> data << endl;
    return;
}

int table::count_root() {
    if (!root) return 0;
    return count_root(root, root -> data);
}		//STEP 2
int table::count_root(node * root, int match) {
    if (!root) return 0;
    int left = count_root(root -> left, match);
    int right = count_root(root -> right, match);
    if (root -> data == match) return left + right + 1;
    return left + right;
}

node * inOrderSuccessor(node *& root) {
    if (!root -> left) {//furthest to the left on subtree
        node * temp = root;
        if (root -> right) {
            root = root -> right;
        }
        else {
            root = nullptr;
        }
        temp -> left = nullptr;
        temp -> right = nullptr;
        return temp;
    }
    else return inOrderSuccessor(root -> left);
}

void table::copy(table & source) {
    copy(root, source.root);

    node * temp = inOrderSuccessor(root -> right);
    temp -> right = root -> right;
    temp -> left = root -> left;
    root -> left = root -> right = nullptr;
    delete root;
    root = temp;
    temp = nullptr;
    return;
}  	//STEP 3
void table::copy(node * & destination, node * source) {
    if (!source) return;
    destination = new node;
    destination -> data = source -> data;
    
    copy(destination -> right, source -> right);
    copy(destination -> left, source -> left);

    return;

}



//Now for the 2-3-4 Tree		//STEP 4
int table::count_3_data()   //sample wrapper function that return the count
{
      return count_3_data(root234);
}	     
     
int table::count_3_data(node234 * root){
    if (!root) return 0;
    int left = count_3_data(root -> child[0]);
    int mleft = count_3_data(root -> child[1]);
    int mright = count_3_data(root -> child[2]);
    int right = count_3_data(root -> child[3]);
    if (root -> data[0] != 0 && root -> data[1] != 0 && root -> data[2] != 0)
        return left + mleft + mright + right + 1;
    return left + mleft + mright + right;
}	                    


//STEP 5
int table::height(){
   if (!root234) return -1; 
   return height(root234);
}                    //Return the height
int table::height(node234 * root){
    if (!root) return 0;
    /*int h = 0;
    for (int i = 0; i < 4; i++) {
        int childHeight = height(root -> child[i]);
        if (childHeight > h) h = childHeight;
    }
    return h + 1;*/
    return height(root -> child[0]) + 1;
}                    

//STEP 6
//Copy from the argument into the data members...
int table::copy_234(table & copy_from) {
    if (!copy_from.root234) return 0;
    return copy(root234, copy_from.root234);
}
int table::copy(node234 * & destination, node234 * source){
    if (!source) return 0;
    destination = new node234;
    for (int i = 0; i < 3; i++) {
        destination -> data[i] = source -> data[i];
    }
    for (int i = 0; i < 4; i++) {
        destination -> child[i] = nullptr;
        copy(destination -> child[i], source -> child[i]);
    }
    return 1;
}
