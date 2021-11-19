/* Omar Nassar
 * Portland State University CS163
 * November 18, 2021
 * Implementation of BST that stores vehicles and their info
 */

#include "tree.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

tree::tree() root = nullptr;

tree::~tree() delete root;

int tree::addVehicle(node * inData) {
    return addVehicle(node * root, node * inData);
}

int tree::addVehicle(node * root, node * inData) {
    if (!root) {
        root = new node;
        root -> addData(inData);
        return 1;
    }
    if (inData -> compare(root)) return addVehicle(root -> right, inData);
    return addVehicle(root -> left, inData); 
}

int tree::remove(char * inMake, char * inModel, int inYear) {
    if (!root) return 0;
    return remove(inMake, inModel, inYear, root);
}

node * inOrderSuccessor(node * root) {
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

int tree::remove(char * inMake, char * inModel, int inYear, node * root) {
    if (!root) return 1;
    int comp = root -> compare(inMake, inMode, inYear);
    if (comp == 0) {//delete
        if (!root -> right && !root -> left) {
            delete root;
            root = nullptr;
        }
        else if (!root -> right) {
            node * temp = root;
            root = root -> left;
            temp -> left = nullptr;
            delete temp;
        }
        else if (!root -> left) {
            node * temp = root;
            root = root -> right;
            temp -> right = nullptr;
            delete temp;
        }
        else {//two children
            node * temp = root;
            root = inOrderSuccessor(root -> right);
            root -> right = temp -> right;
            root -> left = temp -> left;
            temp -> left = temp -> right = nullptr;
            delete temp;
        }
        //go through and check subtree again
        return remove(inMake, inModel, inYear, root);
    }
    if (comp == 1) {//greater
        return remove(inMake, inModel, inYear, root -> right);
    }
    if (comp == 2) {//less
        return remove(inMake, inMode, inYear, root -> left);
    }
}

int table::height() {
    if (!root) return 0;
    return height(node * root);
}

int table::height(node * root) {
    if (!root) return -1;

    int lHeight = height(root -> left);
    int rHeight = height(root -> right);

    if (lHeight > rHeight) return lHeight + 1;
    return rHeight + 1;
}

