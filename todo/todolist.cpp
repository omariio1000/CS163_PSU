#include "todolist."

using namespace std;

/* Omar Nassar
 * CS163
 * Purpose: Aimed at person maintaining software
 * Discuss the data structure
 */

todolist::todo_list() {//Constructor
  head = nullptr;
}

todolist::~todo_list() {//Destructor
  
}

//int insert(char name[], char description[], int priority);
int todolist::insert(char * name, char * description, int priority) {
  //Error checking needs to happen first
  if (!name || !description) return 0; //return 0 when bad data is sent in and can't copy from it
  if (!name[0] || !description[0]) return 0; //incorrect name
  
  node * hold = head;
  head = new node;
  head -> data.name = new char[strlen(name) + 1];
  strcpy(head -> data.name, name);
  head -> data.description = new char[strlen(description) + 1];
  strcpy(head -> data.description, description);
  head -> data.priority = priority;
  return 1;
}

int todolist::insert(const todo_item & to_insert) {//insert item
  
}

int todolist::remove_by_priority(int desired_priority) {

}

int todolist::display_all() {

}

int todolist::display_by_priority(int desired_priority) {

}
