#include "cs163_queue.h"


//Implement these functions using a Circular Linked List
//Add at the rear
int queue::enqueue(const journal_entry & to_add)
{
    //Write the function here
    if (!rear) {
        rear = new q_node;
        rear -> entry.copy_entry(to_add);
        rear -> next = rear;
        return 1;
    }
    
    q_node * temp = rear -> next;
    rear -> next = new q_node;
    rear -> next -> entry.copy_entry(to_add);
    rear = rear -> next;
    rear -> next = temp;
    return 1;
}


//Remove the q_node at the front
int queue::dequeue ()
{

    //Write the function here
    if (!rear) return 0;

    if (rear == rear -> next) {
        delete rear;
        rear = nullptr;
        return 1;
    }
    
    q_node * temp = rear -> next;
    rear -> next = rear -> next -> next;
    delete temp;
    temp = nullptr;
    return 1;
}

