/* Omar Nassar
 * Portland State University CS163
 * October 18, 2021
 * ADT implementation for storing message board using queue
 */

#include "queue.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

using namespace std;

//constructor
queue::queue() { 
    rear = nullptr;
}

//destructor
queue::~queue() {
    while (rear && rear != rear -> next) {
        queue_node * temp = rear -> next;
        rear -> next = temp -> next;
        if (temp -> server) delete [] temp -> server;
        delete temp;
        temp = nullptr;
    }
    if (rear) {
        if (rear -> server) delete [] rear -> server;
        delete rear; 
        rear = nullptr; 
    }
}

//function for enqueueing a stack
int queue::enqueue(stack & inMessages, char * inServer) {
    //if input is invalid
    if (!inServer) return 0;

    //if list doesn't exist yet
    if (!rear) {
        rear = new queue_node;
        inMessages.copyStack(rear -> messages);
        rear -> server = new char[strlen(inServer) + 1];
        strcpy(rear -> server, inServer);
        rear -> next = rear;
        return 1;
    }
    
    //adding new element to list
    queue_node * temp = new queue_node;
    inMessages.copyStack(temp -> messages);
    temp -> server = new char[strlen(inServer) + 1];
    strcpy(temp -> server, inServer);
    temp -> next = rear -> next;
    rear -> next = temp;
    rear = temp;
    return 1;
}

//function for dequeueing 
int queue::dequeue() {
    //if rear doesn't exist can't dequeue
    if (!rear) return 0;

    //if rear's next is rear
    if (rear == rear -> next) {
        delete rear;
        rear = nullptr;
        return 1;
    }

    //otherwise delete first item in list
    queue_node * temp = rear -> next;
    rear -> next = rear -> next -> next;
    delete temp;
    temp = nullptr;
    return 1;
}

//wrapper function for displaying all
int queue::display_all() {
    if (!rear) return 0;
    return display_all(rear -> next);
}

//recursive to display all
int queue::display_all(queue_node * current) {
    cout << endl << "Server Name: " << current -> server << endl;
    current -> messages.display_all();
    if (current != rear) return display_all(current -> next);
    return 1;
}
