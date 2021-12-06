/* Omar Nassar
 * Portland State University CS163
 * November 30, 2021
 * Implementation of node class for graph data structure
 */

#include "node.h"
#include "vertex.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

node::node(char * inRoad) {//constructor
    adjacent = nullptr;
    next = nullptr;
    if (inRoad) {
        road = new char[strlen(inRoad) + 1];
        strcpy(road, inRoad);
    }
}

node::~node() {//destructor
    adjacent = nullptr;
    if (next) delete next;
    next = nullptr;
    if (road) delete road;
    road = nullptr;
} 

//adding adjacent vertex to edge list
int node::addAdjacent(vertex * adding) {
    if (!adding) return 0;
    adjacent = adding;
    return 1;
}

//displaying road name
bool node::displayRoad() {
    if (!road) return false;
    cout << road;
    return true;
}

//displaying adjacent vertex
bool node::displayAdjacent() {
    if (!adjacent) return false;
    adjacent -> displayLocation();
    cout << " using ";
    displayRoad();
    return true;
}

//finding connected vertices with DFS
int node::findConnected(vertex **& visited, int size, int count) {
    count = adjacent -> findConnected(visited, size, count);
    if (next) return next -> findConnected(visited, size, count);
    return count;
}
