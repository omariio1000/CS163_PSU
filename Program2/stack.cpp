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
}

stack::~stack() {
    stack_node * temp = nullptr;

    while (head) {
        temp = head;
        head = head -> next;
        if (temp -> name) delete [] temp -> name;
        temp -> next = nullptr;
        if (temp -> text) delete [] temp -> text;
        delete temp;
        temp = nullptr;
    }
    head = nullptr;
}

int stack::push(char * inName, char * inText) {
    if (!inName || !inText) return 0;

    if (!head) {
        head = new stack_node();
        head -> name = new char[strlen(inName) + 1];
        strcpy(head -> name, inName);
        head -> text = new char[strlen(inText) + 1];
        strcpy(head -> text, inText);
        return 1;
    }

    stack_node * temp = new stack_node();
    temp -> name = new char[strlen(inName) + 1];
    strcpy(temp -> name, inName);
    temp -> text = new char[strlen(inText) + 1];
    strcpy(temp -> text, inText);

    temp -> next = head;
    head = temp;

    return 1;
}

int stack::pop() {
    if (head) {
        stack_node * temp = head;
        head = head -> next;
        delete temp;
        temp = nullptr;
        return 1;
    }
    return 0;
}

int stack::display_all() {
    if (head) return display_all(head);
    return 0;
}

int stack::display_all(stack_node * current) {
    if (current) {
        cout << endl << current -> name << " says:" <<endl;
        cout << current -> text << endl;
        return display_all(current -> next);
    }
    return 1;
}

int stack::copyStack(stack & newStack) {
    if (!head) return 0;
    return copyStack(head, newStack.head);
}

int stack::copyStack(stack_node * current, stack_node *& newCurrent) {
    newCurrent = new stack_node;
    newCurrent -> name = new char[strlen(current -> name) + 1];
    strcpy(newCurrent -> name, current -> name);
    newCurrent -> text = new char[strlen(current -> text) + 1];
    strcpy(newCurrent -> text, current -> text);
    if (current -> next) return copyStack(current -> next, newCurrent -> next);
    return 1;
}
