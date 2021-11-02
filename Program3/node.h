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

        //add data to node by copying from node being passed in
        int addData(node * inData);

        //displaying information of node
        int display();

        //copying data from one node to another
        int copyData(node *& copying);

        //retriving a node's data and copying to argument node
        int retrieve(node *& retrieving);

    private:
        //data being stored in each node
        char * make;
        char * model;
        int year;
        char * color;
        int price;
        int mileage;
        char * information;

        //next node for chaining in hashtable
        node * next;
};

#endif
