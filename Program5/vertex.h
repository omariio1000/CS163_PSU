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

        //functions to compare inputted char* or vertex to location name
        bool compare(char * inLocation);
        bool compare(vertex * comparing);

        //wrapper function to add adjacent vertex
        int addAdjacent(vertex * adding, char * roadName);

        //wrapper function to display adjacent vertices
        int displayAdjacent();

        //function to display location name
        bool displayLocation();

        //functions to find connected vertices using DFS
        int findConnected(vertex **& visited, int size, int count);
        int findConnected(class node * head, vertex **& visited, int size, int count);

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
