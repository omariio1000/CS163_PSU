#include <iostream>
#include <cctype>
#include <cstring>

/*Omar Nassar
 *Portland State University CS163
 *This code will managa a student class which will allow applications
 *to create a student, add a new student, display a student, etc.
 *October 3, 2021
 */

class student {
  
 public:
  student(); //default constructor
  ~student(); //destructor

  int add(char name[], char id[], float grade); //new info to add
  int add(const student & new_student); //add an entire student at once
  int display();
  
 private:
  char * name; //array of characters for full name
  char * id; //psu id number
  float grade;
  
};
