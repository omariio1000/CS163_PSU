#include "table.h"

int duplicateWrapper(node * root) {
    if (!root) return -1;
    else if (!root -> right) return 0;
    return duplicateMax(root);
}

int duplicateMax(node *& root) {
    if (!root -> right) {
        root -> right = new node;
        root -> right -> data = root -> data;
        return root -> data;
    }
    return duplicateMax(root -> right);
}

int removeWrapper(node *& root) {
    if (!root) return 0;
    return removeAll(root);
}

int removeAll(node *& root) {
    if (!root) return 0;
    int left = removeAll(root -> left);
    int right = removeAll(root -> right);
    delete root;
    root = nullptr;
    return 1 + left + right;
}

//not actually needed
int removeLeafWrapper(node * root) {
    if (!root) return 0;
    int removedLeft = removeLeaf(root -> left);
    int removedRight = removeLeaf(root -> right);
    return removedLeft + removedRight;
}

int removeLeaf(node *& root) {
    if (!root) return 0;
    else if (!root -> left && !root -> right) {
        delete root;
        root = nullptr;
        return 1;
    }
    int left = removeLeaf(root -> left);
    int right = removeLeaf(root -> right);

    return left + right;
}

bool checkDuplicate(node * root) {
    if (!root) return false;
    else return checkDuplicate(root -> right, root -> data);
}

bool checkDuplicate(node * root, int inData) {
    if (!root) return false;
    if (root -> data == inData) return true;
    return checkDuplicate(root -> left, inData);
}

int find2Largest(node * root) {
    if (!root) return 0;
    if (!root -> right) {
        cout << endl << "Largest: " << root -> data << endl;
        return 1;
    }  
    return find2Largest(root -> right);
}
