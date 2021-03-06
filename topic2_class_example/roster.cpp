#include "roster.h"

/*Omar Nassar
 *Portland State University CS163
 *Implement member functions for collection of students
 *Uses linear linked list with head and tail pointers
 *October 3, 2021
 */


roster::roster() { //constructor
  head = tail = nullptr;
}

roster::~roster() { //destructor
  node * temp = nullptr;
  while (head) {
	temp = head -> next; //never acces deallocated memory
	delete head;
	head = temp;
  }
  tail = nullptr;
}

int roster::add(const student & new_student) {
  node * temp = new node;
  if (!temp) return 0;
  temp -> data.add(new_student);
  temp -> next = nullptr;
  
  if (!head) {//simple case
	head = tail = temp;
  }
  else {
	tail -> next = temp;
	tail = tail -> next;
  }
  return 1;
}

int roster::display() { //display entire roster
  if (!head) return 0;
  
  node * current = head;
  while (current) {
	current -> data.display();
	current = current -> next;
  }
  return 1;
}
