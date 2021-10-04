#include "student.h"

/*Omar Nassar
 *Portland State University CS163
 *Create a roster of students
 *We can then add, drop, display, advise, etc.
 *October 3, 2021
 */

struct node {

  student data;
  node * next;
  
};

class roster {
 public:
  roster(); //constructor
  ~roster(); //destructor
  int add(const student & new_student);
  int display(); //display entire roster
  
 private:
  node * head;
  node * tail;
};
