#include "cs163_list.h"
using namespace std;

//Sum  all of the data together in a LLL
int list::sum_total()
{
 	//FIRST do this iteratively here. Then recursively
        //COMMENT out the iterative version when  rewriting
        //the solution recursively

        //To solve this recursively write another
        //function:   int sum_total(node * head);
        //and call it from this function
  /*
  int count = 0;
  do {
	count = count + head -> data;
	head = head -> next;
  } while (head -> next != NULL);
  return count + head -> data;
  */
  return list::sum_total(head);
}

//Now implement the function recursively!
int list::sum_total(node * head)
{
  int count = 0;
  if (!head) return 0;
  if (head -> next)
	count += list::sum_total(head -> next);
  return count + head -> data;

}

// *************************************************
//Remove the last node in a LLL. Return false if the
//list is empty and nothing is removed
bool list::remove_last()
{
        //Write your code here
 	//FIRST do this iteratively here. Then recursively
  //COMMENT out the iterative version when  rewriting
  /*
  node * temp = head;
  if (!head) return false;
  while (temp -> next != tail) temp = temp -> next;
  temp -> next = NULL;
  tail = temp;
  return true;
  */
  return remove_last(head, tail);
}

//Now implement the function recursively!
bool list::remove_last(node * & head, node * & tail)
{
  if (!head) return false;
  if (head -> next != tail) return remove_last(head -> next, tail);
  head -> next = NULL;
  tail = head;
  return true;
}

// ************************************************
//Remove all nodes in a LLL. Remove false if there is
//nothing to remove
bool list::remove_all()
{
        //Remove all nodes in a LLL
 	//FIRST do this iteratively here. Then recursively
  //COMMENT out the iterative version when  rewriting
  /*
  if (!head) return false;
  do {
	node * temp = head;
	head = head -> next;
	delete temp;
	temp = nullptr;
  } while (head != tail);
  head = nullptr;
  return true;
  */
  if (!head) return false;
  return remove_all(head);
}

//Now implement the function recursively!
bool list::remove_all(node * & head)
{
  if (!head) return true;
  node * temp = head -> next;
  delete head;
  head = nullptr;
  return remove_all(temp);
}
//return true if the requested item (sent in as an argument)
//is in the list, otherwise return false
bool list::find_item(int item_to_find)
{
  //Write your code here
  /*
  node * temp = head;
  do {
	if (temp -> data == item_to_find) return true;
	temp = temp -> next;
  } while (temp);
  return false;
  */
  if (!head) return false;
  return find_item(head, item_to_find);
}

//Now implement the function recursively!
bool list::find_item(node * head, int item_to_find)
{
  if (!head) return false;
  if (head -> data == item_to_find) return true;
  return find_item(head -> next, item_to_find);
}


// ************************************************
//Make a complete copy of a LLL
bool list::copy(list & from)
{
  //Write your code here
  /*
  node * new_head = new node();
  node * temp = head;
  node * temp2 = new_head;
  do {
	temp2 -> data = temp -> data;
	temp2 -> next = temp -> next;
	temp2 = temp2 -> next;
	temp = temp -> next;
  } while (temp);
  node * new_tail = temp2;
  list::display_list(new_head, new_tail);
  return true;
  */
  
  node * new_head = new node();
  node * new_tail = new node();
  new_head -> data = head -> data;
  new_tail = new_head;
  return copy(new_head, new_tail, head);
}
	//Now implement the function recursively
bool list::copy(node * & dest_head, node * & dest_tail, node * source)
{
  if (!source) {
	//std::cout << dest_tail -> data;
	list::display_list(dest_head, dest_tail);
	return 0;
  }
  dest_tail -> data = source -> data;
  if (source -> next) {
	dest_tail -> next = new node();
	return copy(dest_head, dest_tail -> next, source -> next);
  }
  return copy(dest_head, dest_tail, source -> next);
  
}

int list::display_list(node * print_head, node * print_tail) {
  std::cout << endl << "New linked list: ";
  node * temp = print_head;
  do {
	cout << temp -> data << " ";
	temp = temp -> next;
  } while (temp);
  cout << "and the tail is: " << print_tail -> data << endl << endl;
  return 0;
}

