/* Omar Nassar
 * Portland State University CS163
 * November 15, 2021
 * Binary Search Tree used to store cars and their information
 */

#ifndef tree_h
#define tree_h

#include "node.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

//struct for visual display
struct Trunk {
  Trunk * prev;
  char * str;

  Trunk(Trunk * prev, char * str) {
    this -> prev = prev;
    this -> str = str;
  }
};

class tree {
    public:
        //constructor and destructor
        tree();
        ~tree();

        //wrapper to add vehicle to tree
        int addVehicle(node * inData);

        //wrapper to remove matching vehicles
        int remove(char * inMake, char * inModel, int inYear);

        //wrapper to find height of tree
        int height();
        
        //wrapper to find efficiency of tree
        int efficiency();

        //wrapper to retrieve matching vehicles
        int retrieve(char * inMake, char * inModel, int inYear, node **& retrieving, bool single, int size);
        
        //wrapper to display all
        int displayAll();

        //wrapper to find price range
        int priceRange();
        
        //loading data from file
        int loadData(char * fileName);

    private:
        //recursive functions
        int addVehicle(node *& root, node * inData);
        int retrieve(char * inMake, char * inModel, int inYear, node**& retrieving, node * root);
        int remove(char * inMake, char * inModel, int inYear, node *& root);
        int height(node * root);
        int retrieve(char * inMake, char * inModel, int inYear, node **& retrieving, node * root, bool single, int size);
        int displayAll(node * root, int level);
        int visualDisplay(node * root, Trunk * prev, bool isLeft);
        int displayVehicle(char * inMake, char * inModel, int inPrice, node * root);
        int priceAdd(node *& priceRoot, node * inData);
        int copyOver(node *& priceRoot, node * root);

        node * root;

};

#endif
