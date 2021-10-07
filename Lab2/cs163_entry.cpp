#include "cs163_entry.h"


//Step #7: Implement this function
//This function takes the argument and copies it into
//the journal's data members
int journal_entry::copy_entry(const journal_entry & copy_from)
{ 
  //Place your code here
  title = new char[strlen(copy_from.title) + 1];
  strcpy(title, copy_from.title);

  notes = new char[strlen(copy_from.notes) + 1];
  strcpy(notes, copy_from.notes);
  
}


//Step #8: Implement this function
//This function will return non-zero if the title sent
//in as an argument matches the data member. It supplies
//the matching journal back as an argument
int journal_entry::retrieve(char * matching_title, journal_entry & found)
{

  //Place your code here
  if (strcmp(found.title, matching_title) == 0) return 1;
  return 0;

}

