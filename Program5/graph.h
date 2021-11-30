/* Omar Nassar
 * Portland State University CS163
 * November 29, 2021
 * Adjacency list graph data structure for mapping roads
 */

#ifndef graph_h
#define graph_h

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

#include "vertex.h"
#include "node.h"

class graph {
    public:
        graph();
        ~graph();

        int displayAll();
        int findVertex(char * location);
        int insertVertex(char * location);
        int insertEdge(char * firstLocation, char * secondLocation, char * roadName);
        int displayAdjacent(char * location);
        int displaySingle(char * location);

    private:
        vertex * adjacencyList;
        int list_size;
};

#endif