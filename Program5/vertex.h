/* Omar Nassar
 * Portland State University CS163
 * November 29, 2021
 * Vertex class for graph data structure mapping roads
 */

#ifndef vertex_h
#define vertex_h

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

#include "node.h"

class vertex {
    public:
        vertex(char * inLocation);
        ~vertex();

        int compare(char * inLocation);
        int addAdjacent(vertex * adding, char * roadName);
        int displayAdjacent();
        int displayLocation();

    private:
        char * location;
        node * head;
};

#endif
