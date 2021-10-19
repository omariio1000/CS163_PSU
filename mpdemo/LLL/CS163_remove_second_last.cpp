#include "list.h"

//remove the second to last node in a LLL
//will have a wrapper for nonrepetitive work
//return data for node being removed

int remove_before_last(node * & head) {
    if (!head) return 0;
    if (!head -> next) return 0;
    return recursive_before_last(head);
}

int recursive_before_last(node * & head) {
    if (!head -> next -> next) {
        node * hold = head -> next;
        int hold_data = head -> data;
        delete head;
        head = hold;
        return hold_data;
    }
    return recursive_before_last(head -> next);
}
