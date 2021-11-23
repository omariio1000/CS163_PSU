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

class tree {
    public:
        //constructor and destructor
        tree();
        ~tree();

        //wrapper to add vehicle to tree
        int addVehicle(node * inData);

        //wrapper to retrieve matching vehicles
        int retrieve(char * inMake, char * inModel, int inYear, node **& retrieving);

        //wrapper to remove matching vehicles
        int remove(char * inMake, char * inModel, int inYear);

        //wrapper to find height of tree
        int height();
        
        //wrapper to find efficiency of tree
        int efficiency();

        int retrieve(char * inMake, char * inModel, int inYear, node **& retrieving, bool single);

        //loading data from file
        int loadData(char * fileName);

    private:
        //recursive functions
        int addVehicle(node *& root, node * inData);
        int retrieve(char * inMake, char * inModel, int inYear, node**& retrieving, node * root);
        int remove(char * inMake, char * inModel, int inYear, node * root);
        int height(node * root);
        int retrieve(char * inMake, char * inModel, int inYear, node **& retrieving, node * root, bool single);

        node * root;

};

#endif
