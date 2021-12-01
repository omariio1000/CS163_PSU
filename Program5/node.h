/* Omar Nassar
 * Portland State University CS163
 * November 29, 2021
 * Node class for graph data structure mapping roads
 */

#ifndef node_h
#define node_h

#include "vertex.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

class node {
    public:
        //constructor and destructor
        node(char * inRoad);
        ~node();

        //function to add adjacent vertex
        int addAdjacent(class vertex * adding);

        //function to display road name (weight)
        bool displayRoad();

        //function to display adjacent vertex
        bool displayAdjacent();
        
        //next pointer for edge list
        node * next;
    private:
        //adjacent vertex 
        //(using class before type because wasn't working before)
        class vertex * adjacent;

        //road name (weight)
        char * road;
};

#endif
