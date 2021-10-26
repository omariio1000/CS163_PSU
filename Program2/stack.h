/*Omar Nassar
 *Portland State University CS163
 *October 18, 2021
 *ADT for messages (Stack using LLL)
 */

#ifndef stack_h
#define stack_h

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

struct message {
    char * name = nullptr;
    char * text = nullptr;
};

struct stack_node {
    message * data = nullptr;
    stack_node * next = nullptr;
};

const int SIZE = 5;

class stack {
    public:
        stack();
        ~stack();

        int push(char * inName, char * inText);
        int pop();  
        int display_all();
        int copyStack(stack & newStack);

    private:
        stack_node * head;
        int top_index;
        int display_all(stack_node * current, int index);
        int copyStack(stack_node * current, stack_node *& newCurrent);
};

#endif
