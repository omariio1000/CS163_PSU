#include "student.h"

using namespace std;

/*Omar Nassar
 *Portland State University CS163
 *Implememnt member funcitons of student class
 *October 3, 2021
 */

student::student() { //default constructor
  name = nullptr;
  id = nullptr;
  grade = 0.0;
}

student::~student() { //destructor
  if (name) delete [] name;
  if (id) delete [] id;

  name = id = nullptr;
  grade = 0.0;
}

int student::add(char inName[], char inID[], float inGrade) { //new info to add
  if (!inName || !inID) return 0;
  
  name = new char[strlen(inName) + 1];
  strcpy(name, inName);
  id = new char[strlen(inID) + 1];
  strcpy(id, inID);
  grade = inGrade;

  return 1;
}

int student::add(const student & new_student) {//add new student all at once
  return add(new_student.name, new_student.id, new_student.grade);
}

int student::display() {
  cout << name << '\t' << id << '\t' << "Grade: " << grade << '%' << endl;
  
  return 1;
}
