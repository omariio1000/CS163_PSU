/*
 *
 */

#include "list.h"
//to compile we need to g++ our_file main.cpp *.o

//Remove the last node from a LLL and return the count
//Stopping condition: If next is NULL (last node in list)

int remove_last_recursive(node * & head)
{
  int count = 0;
  if (!head) return 0; //base case
  if (!head -> next)
	{
	  delete head;
	  head = NULL;
	  return 1;
	}
  ++count;
  count += remove_last_recursive(head -> next);
  return count;
}

int remove_last_refined(node * & head)
{
  if (!head) return 0; //base case
  if (!head -> next)
	{
	  delete head;
	  head = NULL;
	  return 1;
	}
  return remove_last_refined(head -> next) + 1;
}

//Remove the largest item in a linear linked list (remove all occurences) and return how many removed
//No stopping condition (other than head is null)

//Wrapper
int remove_largest(node * & head)
{
  if (!head) return 0; //empty list
  int largest = head -> data;
  
  return remove_largest(head, largest);
}

int remove_largest(node * & head, int & largest)
{
  if (!head) return 0; //base case
  if (largest < head -> data) //update largest
	largest = head -> data;
  int counter = remove_largest(head -> next, largest);
  //time to remove as we unwind the stack
  if (head -> data == largest)
	{
	  node * temp = head -> next; //hold onto the next
	  delete head; //release the node
	  head = temp; //update head around the deleted node
	  ++counter;
	}
  return counter;
}

//Removing the last node and then counting how many times the last node's data existed in the list
//Return type is representing the count
int remove_and_count(node * & head, int & last_nodes_data) {
  if (!head) return 0;
  if (!head -> next) {
	last_nodes_data = head -> data;
	delete head;
	head = NULL;
	return 0;
  }
  int count = remove_and_count(head -> next, last_nodes_data);
  if (head -> data == last_nodes_data)
	++count;
  return count;
}
