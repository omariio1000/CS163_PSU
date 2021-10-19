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

struct stack_node {
    char * name;
    char * text;
    stack_node * next;
};

class stack {
    public:
        stack();
        ~stack();

        int push(char * inName, char * inText);
        int pop();  
        int display_all();
        //int copyStack(stack & newStack);

    private:
        stack_node * head;
        int display_all(stack_node * current);
};

#endif
