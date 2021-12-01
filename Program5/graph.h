/* Omar Nassar
 * Portland State University CS163
 * November 29, 2021
 * Adjacency list graph data structure for mapping roads
 */

#ifndef graph_h
#define graph_h

#include "vertex.h"
#include "node.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>


class graph {
    public:
        //constructor and destructor
        graph(int size);
        ~graph();

        //function to display all
        int displayAll();

        //function to find vertex (used for other functions)
        int findVertex(char * location, vertex *& found);

        //function to insert vertex
        int insertVertex(char * location);

        //function to add edge between vertices
        int insertEdge(char * firstLocation, char * secondLocation, char * roadName);

        //functions to display vertices that are adjacent to this node
        int displayAdjacent(char * location);
        int displayAdjacent(vertex * displaying);

    private:
        vertex ** adjacencyList;
        int listSize;
};

#endif
