#include "cs163_list.h"
using namespace std;




//Implement these three functions
//Add to the end of the LLL as efficiently as possible
int list::add(journal_entry & to_add)
{
   
  node * adding = new node();
  //adding -> entry = new journal_entry();
  adding -> entry.copy_entry(to_add);
  //Implement this function using the
  //journal entry functions we just wrote!
  if (!head) {
	head = adding;
	tail = adding;
	return 1;
  }
  else {
	tail -> next = adding;
	tail = adding;
	return 1;
  }
}



//Display all journal entries
//Return false if there are no entries
int list::display(void)
{
  if (!head) return false;
  //Your code goes here!
  node * current = head;
  while (current) {
	current -> entry.display();
	current = current -> next;
  }
  return true;
}

//Determine if there is a match with the title passed in
//and if so provide the matching journal entry back to the
//client program through the second argument.
//Return a zero if no match is found
int list::find(char matching_title[], journal_entry & found)
{
  //Your code goes here!           
  node * current = head;
  while (head) {
	if (head -> entry.retrieve
		(matching_title, current -> entry) != 0) {
	  found.copy_entry(current -> entry);
	  return 1;
	}
	else head = head -> next;
  }
  return 0;
}


//Copy the list passed in as an argument
//and add the nodes to the end of the current list
int list::append(list & source)
{
  
  //Your code goes here!
  
  node * current = source.head;
  cout << "appending: ";
  current -> entry.display();
  cout << endl;
  while (current) {
	add(current -> entry);
	current = current -> next;
  }
  return 0;
  
}
