/* Omar Nassar
 * Portland State University CS163
 * November 29, 2021
 * Vertex class for graph data structure mapping roads
 */

#ifndef vertex_h
#define vertex_h

#include "node.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

class vertex {
    public:
        //constructor and destructor
        vertex(char * inLocation);
        ~vertex();

        //function to compare inputted char* to location name
        bool compare(char * inLocation);

        //wrapper function to add adjacent vertex
        int addAdjacent(vertex * adding, char * roadName);

        //wrapper function to display adjacent vertices
        int displayAdjacent();

        //function to display location name
        bool displayLocation();

    private:
        //name of location/intersection    
        char * location;
        //edge list head pointer
        class node * head;

        //recursive functions
        int addAdjacent(class node *& head, vertex * adding, char * roadName);
        int displayAdjacent(class node * head);
};

#endif
