//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
//Write your function prototype here:

float average_calc(node * head);
int counts_and_sums(node * head, int & sum);
/*
int remove_last_recursive(node * & head);
int remove_last_refined(node * & head);
int remove_largest(node * & head);
int remove_largest(node * & head, int & largest);
int append_end(node * & head);
int append_end(node * & head, int data);
*/
