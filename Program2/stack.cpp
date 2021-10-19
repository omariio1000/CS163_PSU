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
    stack_node * temp;
    do {
       temp = head -> next;
       delete head;
       head = temp;
    } while (head);
    head = nullptr;
}

int stack::push(char * inName, char * inText) {
    if (!inName || !inText) return 0;

    if (!head) {
        head = new stack_node();
        head -> name = inName;
        head -> text = inText;
        return 1;
    }

    stack_node * temp = new stack_node();
    temp -> name = inName;
    temp -> text = inText;

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
/*
int stack::copyStack(stack & newStack) {
    return 0;
}
*/
