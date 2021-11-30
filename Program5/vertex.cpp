/* Omar Nassar
 * Portland State University CS163
 * November 30, 2021
 * Implementation of vertex class for graph data structure
 */

#include "vertex.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

vertex::vertex(char * inLocation) {
    head = nullptr;
    if (inLocation) {
        location = new char[strlen(inLocation) + 1];
        strcpy(location, inLocation);
    }
}

vertex::~vertex() {
    if (location) delete location;
    location = nullptr;
    if (head) delete head;
    head = nullptr;
}
