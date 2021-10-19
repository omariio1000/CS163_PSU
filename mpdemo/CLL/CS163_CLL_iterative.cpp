#include "clist.h"

/* Display every node that is odd starting with first node
 * We have a rear pointer
 * Iterative
 */

int display_odd_values(node * rear) {
    //If rear is null then there is nothing to display
    if (!rear) return 0;

    if (!rear -> next) {
        if (rear -> data % 2 != 0) { 
            cout << endl << rear -> data << endl;
            return 1;
        }
        return 0;
    }
    
    node * current = rear -> next; //start at "first node"
    int counter {0};
    do {
        if (current -> data % 2 != 0) { 
            cout << endl << current -> data << endl;
            ++counter;
        }
        current = current -> next;
    } while (current != rear -> next);

    return counter;

}
