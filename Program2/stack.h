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

struct message {//data stored in each stack node
    char * name = nullptr;
    char * text = nullptr;
};

struct stack_node {//each node in the stack
    message * data = nullptr;
    stack_node * next = nullptr;
};

//size of array for stack
const int SIZE = 5;

class stack {
    public:
        //constructor and destructor
        stack();
        ~stack();

        //push function
        int push(char * inName, char * inText);
        //pop function
        int pop();  
        //function to display all
        int display_all();
        //function to copy stack (for enqueueing)
        int copyStack(stack & newStack);

    private:
        //head pointer for stack linked list
        stack_node * head;
        //current index to push to
        int top_index;
        //recursive function for displaying all
        int display_all(stack_node * current, int index);
        //recursive function for copying stack
        int copyStack(stack_node * current, stack_node *& newCurrent);
};

#endif
