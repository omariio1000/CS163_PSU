#include "list.h"

//Add a node to the end of a LLL
void add_end(node * & head, int new_data) {
    if (!head) {
        head = new node;
        head -> data = new_data;
        head -> next = NULL;
        return;
    }

    add_end(head -> next, new_data);
}
