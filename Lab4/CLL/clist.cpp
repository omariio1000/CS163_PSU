#include "clist.h"

//Here are the funcitons that we will be writing in lab for CLL
int list::remove_entire()
{
    if (!rear) return 0;
    return remove_entire(rear);
}

int list::remove_entire(node * & rear)
{
    if (rear == rear -> next) {
        delete rear;
        rear = nullptr;
        return 1;
    }
    node * temp = rear -> next;
    rear -> next = temp -> next;
    delete temp;
    return remove_entire(rear);
}

int list::count_all()
{
    if (!rear) return 0;
    return count_all(rear -> next);
}

int list::count_all(node * current)
{
    if (!current) return 0;
    if (current == rear) return rear -> data;
    return current -> data + count_all(current -> next);
}
