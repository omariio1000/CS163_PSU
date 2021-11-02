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
 
int display_inorder(node * root);
