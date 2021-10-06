/*
 *
 */

#include "list.h"

//Wrapper function
int append_end(node * & head) {
  if (!head) return 0;
  return append_end(head -> next, head -> data);
}

//Recursive to add at the end
int append_end(node * & head, int data) {
  if (!head) {
	head = new node;
	head -> data = data;
	head -> next = NULL;
	return 1;
  }
  
  if (head -> data == data)	return append_end(head -> next , data) + 1;
  return append_end(head -> next, data);
}
