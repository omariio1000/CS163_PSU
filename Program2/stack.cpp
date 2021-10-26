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

stack::stack() {
    head = nullptr;
    top_index = 0;
}

stack::~stack() {
    stack_node * temp = nullptr;

    while (head) {
        temp = head;
        head = head -> next;
        if (temp -> data) delete [] temp -> data;
        temp -> next = nullptr;
        delete temp;
        temp = nullptr;
    }
    head = nullptr;
}

int stack::push(char * inName, char * inText) {
    if (!inName || !inText) return 0;

    if (!head) {
        head = new stack_node();
        head -> data = new message[SIZE];
    }
    
    if (top_index == SIZE) {
        stack_node * temp = head;
        head = new stack_node;
        head -> data = new message[SIZE];
        head -> next = temp;
        top_index = 0;
    }
    
    head -> data[top_index].name = new char[strlen(inName) + 1];
    strcpy(head -> data[top_index].name, inName);
    head -> data[top_index].text = new char[strlen(inText) + 1];
    strcpy(head -> data[top_index].text, inText);
    
    ++top_index;

    return 1;
}

int stack::pop() {
    if (!head) return 0;

    --top_index;

    if (top_index < 0) {
        stack_node * temp = head -> next;
        delete head;
        head = temp;
        top_index = SIZE;
    }
    return 1;
}

int stack::display_all() {
    if (head) return display_all(head, top_index - 1);
    return 0;
}

int stack::display_all(stack_node * current, int index) {
    if (!current || !current -> data[index].name) return 1; 

    cout << endl << current -> data[index].name << " says:" <<endl;
    cout << current -> data[index].text << endl;
    --index;
    if (index < 0) return display_all(current -> next, SIZE - 1);
    return display_all(current, index);
    
}

int stack::copyStack(stack & newStack) {
    if (!head) return 0;
    newStack.head = new stack_node;
    newStack.head -> data = new message[SIZE];
    newStack.top_index = top_index;
    return copyStack(head, newStack.head);
}

int stack::copyStack(stack_node * current, stack_node *& newCurrent) {
    if (!current) return 1;
    newCurrent = new stack_node;
    newCurrent -> data = new message[SIZE];
    int index = 0;
    while (current -> data[index].name) {
        newCurrent -> data[index].name = new char[strlen(current -> data[index].name) + 1];
        strcpy(newCurrent -> data[index].name, current -> data[index].name);
        newCurrent -> data[index].text = new char[strlen(current -> data[index].text) + 1];
        strcpy(newCurrent -> data[index].text, current -> data[index].text);
        ++index;
    }
    return copyStack(current -> next, newCurrent -> next);
}
