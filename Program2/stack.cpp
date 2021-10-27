/*Omar Nassar
 *Portland State University CS163
 *October 18, 2021
 *ADT implementation for message storing using stack
 */

#include "stack.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

using namespace std;

//constructor
stack::stack() {
    head = nullptr;
    top_index = 0;
}

//destructor
stack::~stack() {
    stack_node * temp = nullptr;

    while (head) {
        temp = head;
        head = head -> next;
        delete [] temp -> data;
        temp -> data = nullptr;
        temp -> next = nullptr;
        delete temp;
        temp = nullptr;
    }
    head = nullptr;
}

//push function to push to stack
int stack::push(char * inName, char * inText) {
    //if input is invalid
    if (!inName || !inText) return 0;

    //if list still doesn't exist
    if (!head) {
        head = new stack_node();
        head -> data = new message[SIZE];
    }

    //if the index is past the size of the array
    if (top_index == SIZE) {
        stack_node * temp = head;
        head = new stack_node;
        head -> data = new message[SIZE];
        head -> next = temp;
        top_index = 0;
    }
    
    //copying over data from input to stack
    head -> data[top_index].name = new char[strlen(inName) + 1];
    strcpy(head -> data[top_index].name, inName);
    head -> data[top_index].text = new char[strlen(inText) + 1];
    strcpy(head -> data[top_index].text, inText);
    
    ++top_index;

    return 1;
}

//function to pop off stack
int stack::pop() {
    //if head doesnt exist then return
    if (!head || !head -> data[top_index - 1].name) return 0;

    --top_index;
    
    //index nonexistant
    if (top_index == 0) {
        stack_node * temp = head -> next;
        head -> next = nullptr;
        display_single(head -> data[top_index]);
        delete head;
        head = temp;
        top_index = SIZE;
    }
    else {
        display_single(head -> data[top_index]);
        delete[] head -> data[top_index].name;
        head -> data[top_index].name = nullptr;
        delete[] head -> data[top_index].text;
        head -> data[top_index].text = nullptr;
    }
    return 1;
}

//wrapper function to display all
int stack::display_all() {
    if (head && head -> data[top_index - 1].name) return display_all(head, top_index - 1);
    //if head doesnt exist return 0
    return 0;
}

//recursive for displaying all
int stack::display_all(stack_node * current, int index) {
    if (!current || !current -> data[index].name) return 1; 

    display_single(current -> data[index]);
    //cout << endl << current -> data[index].name << " says:" <<endl;
    //cout << current -> data[index].text << endl;
    --index;
    if (index < 0) return display_all(current -> next, SIZE - 1);
    return display_all(current, index);
    
}

//function to display single item
int stack::display_single(message displaying) {
    cout << endl << displaying.name << " says:" << endl;
    cout << displaying.text << endl;
    return 1;
}

//wrapper function to copy stack
int stack::copyStack(stack & newStack) {
    if (!head) return 0;
    //initialize new stack
    newStack.head = new stack_node;
    newStack.head -> data = new message[SIZE];
    newStack.top_index = top_index;

    return copyStack(head, newStack.head);
}

//recursive functiont o copy stack
int stack::copyStack(stack_node * current, stack_node *& newCurrent) {
    //if next node doesnt exist
    if (!current) return 1;

    //making new current a new node
    newCurrent = new stack_node;
    newCurrent -> data = new message[SIZE];
    int index = 0;

    //copy each element in array to new array
    while (current -> data[index].name) {
        newCurrent -> data[index].name = new char[strlen(current -> data[index].name) + 1];
        strcpy(newCurrent -> data[index].name, current -> data[index].name);
        newCurrent -> data[index].text = new char[strlen(current -> data[index].text) + 1];
        strcpy(newCurrent -> data[index].text, current -> data[index].text);
        ++index;
    }
    return copyStack(current -> next, newCurrent -> next);
}
