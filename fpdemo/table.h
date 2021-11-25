//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;;
};

void build(node * & root);  //supplied
void display(node *  root); //supplied
void destroy_all (node * & root); //we will write

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
 
void insert_BST(node *& head, int to_add);
int display_inorder(node * root);

int duplicateWrapper(node * root);
int duplicateMax(node *& root);

int removeWrapper(node *& root);
int removeAll(node *& root);

int removeLeafWrapper(node * root);
int removeLeaf(node *& root);

bool checkDuplicate(node * root);
bool checkDuplicate(node * root, int data);
