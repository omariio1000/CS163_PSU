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

struct queue_node {
    stack * messages;
    queue_node * next;
};

class queue {
    public:
        queue();
        ~queue();

        int enqueue(stack * inMessages);
        int dequeue();
        int display_all();
    private:
        queue_node * head;
};

#endif
