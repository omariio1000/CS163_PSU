/*Omar Nassar
 *Portland State University CS163
 *October 18, 2021
 *ADT to store different message board stacks (Queue using CLL)
 */

#ifndef queue_h
#define queue_h

#include "stack.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

struct queue_node {//each node in queue
    stack messages;
    char * server = nullptr;
    queue_node * next = nullptr;
};

class queue {
    public:
        //constructor and destructor
        queue();
        ~queue();

        //function for enqueueing
        int enqueue(stack & inMessages, char * inserver);
        //function for dequeueing
        int dequeue();
        //function to display all
        int display_all();
    private:
        //pointer for rear in CLL
        queue_node * rear;
        //recursive function to display all
        int display_all(queue_node * current);
};

#endif
