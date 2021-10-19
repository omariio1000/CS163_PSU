#include "clist.h"

/* Recursive version of displaying all odd data in a CLL
 * And return the number of items displayed
 * Wrapper funciton to do non-repetitive list
 */

int display_odd (node * rear) {
    if (!rear) return 0;
    
    if (rear == rear -> next) {
        if (rear -> data % 2 != 0) {
            cout << rear -> data << endl;
            return 1;
        }
        return 0;
    }
    return display_odd(rear -> next, rear);
}

int display_odd(node * current, node * real_rear) {
    if (current == real_rear) {
        if (current -> data % 2 != 0) {
            cout << current -> data << endl;
            return 1;
        }
        return 0;
    }

    if (current -> data % 2 != 0) {
        cout << current -> data << endl;
        return 1 + display_odd(current -> next, real_rear);
    }
    return display_odd(current -> next, real_rear);
}
