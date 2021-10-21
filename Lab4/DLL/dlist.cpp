#include "dlist.h"

//Here are the functions you will be implementing for doubly linked lists
//

int list::insert_after(int to_add)
{
    if (!head) return 0;
    return insert_after(head, to_add);
}

int list::insert_after(node * & head, int to_add)
{
    if (!head) return 0; 
    if (head -> data == 2) {
        node * temp = new node;
        temp -> data = to_add;
        temp -> next = head -> next;
        if (head -> next) temp -> next -> previous = temp;
        else tail =temp;
        head -> next = temp;
        temp -> previous = head;
    }
    return insert_after(head -> next, to_add) + 1;
}

int list::insert_before(int to_add)
{
    if (!head) return 0;
    return insert_before(head, to_add);
}

int list::insert_before(node * & head, int to_add)
{
    if (!head) return 0;
    if (head -> data == 2) {
        node * temp = head;
        head = new node;
        head -> data = to_add;
        head -> next = temp;
        head -> previous = temp -> previous;
        temp -> previous = head;
        return insert_before(temp -> next, to_add) + 2;
    }
    return insert_before(head->next, to_add) + 1;
}

int list::display_last_two()
{
    
}

int list::display_last_two(node * head)
{

}

int list::remove_last_two()
{

}

int list::remove_last_two(node * & head)
{

}

     

