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

}

stack::~stack() {

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
    return 0;
}

int stack::display_all() {
    return 0;
}

int stack::copyStack(stack & newStack) {
    return 0;
}
