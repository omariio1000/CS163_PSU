/* Omar Nassar
 * Portland State University CS163
 * November 29, 2021
 * Node class for graph data structure mapping roads
 */

#ifndef node_h
#define node_h

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

#include "vertex.h"

class node {
    public:
        node(char * inRoad);
        ~node();

        int addAdjacent(vertex * adding);
        int displayRoad();
        
        node * next;
    private:
        vertex * adjacent;
        char * road;
};

#endif
