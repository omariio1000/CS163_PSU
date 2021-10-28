#include "cs163_table.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the hash table and initialize each
      //element and data member.
      hash_table = new node*[size];
      for (int i = 0; i < size; i++) {
          hash_table[i] = nullptr;
      }
      hash_table_size = size;

}
//Do something with the key being passed 
//in and return a number(or in our case an index)
//Make sure you're within the array size!
int table::hash_function(char *key) const
{
    //Place your code here
    int index;
    if (!key[0] || !key[1] || key[2])
        index = key[0] + key[1] * key[2];
    index = index % hash_table_size;
    return index;

}

//Using a hash function, insert a new value into the 
//head of the chain
int table::insert(char * key_value, const journal_entry & to_add)
{
    if (!hash_table || !key_value) return 0;

        //Place your code here
    int index = hash_function(key_value);
    if (!hash_table[index]) {
        hash_table[index] = new node;
        hash_table[index] -> entry.copy_entry(to_add);
    }
    
    else {
        node * adding = hash_table[index];
        while (adding -> next) 
            adding = adding -> next;
        
        adding -> next = new node;
        adding -> next -> entry.copy_entry(to_add);
    }
    return 1;

}

//Using a hash function determine which chain to search
//then return 0 if no match is found
int table::retrieve(char * title_to_find, journal_entry & found) const
{

        //Place your code here
    if (!hash_table || !title_to_find) return 0;
    int index = hash_function(title_to_find);
    if (!hash_table[index]) return 0;

    if (hash_table[index] -> entry.retrieve(title_to_find, found) == 1)
        return 1;

    node * finding = hash_table[index];
    while (finding -> next) {
        finding = finding -> next;
        if (finding -> entry.retrieve(title_to_find, found))
                return 1;
    }
    
    return 0;



}

