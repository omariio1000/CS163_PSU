#include "cs163_stack.h"


//These are the functions you will be implementing
//for this lab, using a linear linked list of arrays
//as the data structure

//Add a new item to the top of stack
int stack::push(const journal_entry & to_add)
{
    //Implement the function here
    if (!head) {
        head = new node;
        head -> entries = new journal_entry[MAX];

        top_index = 1;

    }
    
    if (top_index > MAX) {
        node * temp = head;
        head = new node;
        head -> next = temp;
        top_index = 0;
    }
    
    head -> entries[top_index].copy_entry(to_add);
    ++top_index;
    return top_index;    
}

//Remove the top of stack
int stack::pop (void)
{
    //Implement the function here
    if (!head) return 0;
    
    --top_index;

    if (top_index < 0) {
        node * temp = head -> next;
        delete head;
        head = temp;
        top_index = MAX;
    }
    return 1;
}

//Supply the journal at the top of stack back to the client
//Return 0 if there are no items
//top_index is one beyond where the top of stack is...
//with no items, top_index is zero
int stack::peek(journal_entry & found_at_top) const
{
    //Implement the function here
    if (!head) return 0;
    found_at_top = head -> entries[top_index - 1];
}

