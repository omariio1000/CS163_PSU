/* Omar Nassar
 * Portland State University CS163
 * November 30, 2021
 * Implementation of node class for graph data structure
 */

#include "node.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

node::node(char * inRoad) {
    adjacent = nullptr;
    next = nullptr;
    if (inRoad) {
        road = new char[strlen(inRoad) + 1];
        strcpy(road, inRoad);
    }
}

node::~node() {
    adjacent = nullptr;
    if (next) delete next;
    next = nullptr;
    if (road) delete road;
    road = nullptr;
} 

int node::addAdjacent(vertex * adding) {
    if (!adding) return 0;
    adjacent = adding;
    return 1;
}

int node::displayRoad() {
    cout << road;
}
