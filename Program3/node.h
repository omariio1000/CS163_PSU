/* Omar Nassar
 * Portland State University CS163
 * November 1, 2021
 * Node class to hold information for vehicles hash table
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

        //add data to node by passing in all args
        int addData(char * inMake, char * inModel, char * inColor, char * inInformation, int inYear, int inPrice, int inMileage);

        //add data to node by copying from node being passed in
        int addData(node * inData);

        //displaying information of node
        int display();

        //comparing make and model to node's data
        bool compare(char * inMake, char * inModel);

        node * next;

    private:
        //data being stored in each node
        char * make;
        char * model;
        char * color;
        char * information;

        int year;
        int price;
        int mileage;

        //next node for chaining in hashtable
        //node * next;
};

#endif
