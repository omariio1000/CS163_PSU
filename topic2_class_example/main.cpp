#include "roster.h"

using namespace std;

/*Omar Nassar
 *Portland State University CS163
 *This code is aimed at testing the software created
 *October 3, 2021
 */

int main () {
  
  char name[21];
  char id[13];
  float grade;
  student object;

  cout << "Please enter student name: ";
  cin.get(name, 21, '\n');
  cin.ignore(100, '\n');

  cout << "Now enter id: ";
  cin.width(13);
  cin >> id;
  cin.ignore(100, '\n');

  cout << "Now enter grade percentage: ";
  cin >> grade;
  cin.ignore(100, '\n');

  object.add(name, id, grade);
  object.display();
  

  //Test roster
  roster students;

  students.add(object);
  students.add(object);
  students.add(object);

  students.display();
  
  return 0;  
}
