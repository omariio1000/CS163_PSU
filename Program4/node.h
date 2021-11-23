/* Omar Nassar
 * Portland State University CS163
 * November 15, 2021
 * Node class to hold information for vehicles for Binary Search Tree
 */

#ifndef node_h
#define node_h

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

class node {
    public:
        //constructor and destructor
        node();
        ~node();

        //add data functions 
        int addData(char * inMake, char * inModel, char * inColor, char * inInfo, int inYear, int inPrice, int inMiles);
        int addData(node * inData);

        //display node information
        int display();

        //display price
        int displayPrice();

        int displayVisual();

        //compare data vs arg node's data (greater or lower)
        bool compare(node * comparing);
        int compare(char * inMake, char * inModel, int inYear);

        bool comparePrice(node * comparing);

        //children nodes
        node * left;
        node * right;

    private:
        //data being stored
        char * make;
        char * model;
        char * color;
        char * information;

        int year;
        int price;
        int mileage;
};

#endif
