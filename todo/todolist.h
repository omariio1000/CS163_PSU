#include <iostream>
#include <cctype>
#include <cstring>

/* Omar Nassar
 * CS163
 * Purpose:
 */

struct todo_item {
  char * name;
  char * description;
  int priority;
};

struct node {
  todo_item data;
  node * next;
};

class todolist {

public:
  todo_list();
  ~todo_list();
  //int insert(char name[], char description[], int priority);
  int insert(const todo_item & to_insert);
  int insert(char * name, char * description, int priority);
  int remove_by_priority(int desired_priority);
  int display_all();
  int display_by_priority(int desired_priority);
  
private:
  node * head;
  
};
