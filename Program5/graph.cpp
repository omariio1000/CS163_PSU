/* Omar Nassar
 * Portland State University CS163
 * November 30, 2021
 * Implementation of adjacency list class for graph data structure
 */

#include "graph.h"
#include "vertex.h"
#include "node.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

graph::graph(int size) {//constructor
    adjacencyList = new vertex*[size];
    for (int i = 0; i < size; i++) adjacencyList[i] = nullptr;
    listSize = size;
}

graph::~graph() {//destructor
    for (int i = 0; i < listSize; i++) {
        if (adjacencyList[i]) {
            delete adjacencyList[i];
            adjacencyList[i] = nullptr;
        }
    }
    delete[] adjacencyList;
    adjacencyList = nullptr;
}

//displaying all vertices in adjacency list
int graph::displayAll() {
    for (int i = 0; i < listSize; i++) {
        if (adjacencyList[i]) displayAdjacent(adjacencyList[i]);
    }
    return 1;
}

//finding certain vertex based on name
int graph::findVertex(char * location, vertex *& found) {
    for (int i = 0; i < listSize; i++) {
        if (adjacencyList[i]) {
            if (adjacencyList[i] -> compare(location)) {
                found = adjacencyList[i];
                return 1;
            }
        }
    }
    found = nullptr;
    return 0;
}

//inserting vertex to adjacency table
int graph::insertVertex(char * location) {
    for (int i = 0; i < listSize; i++) {
        if (!adjacencyList[i]) {
            adjacencyList[i] = new vertex(location);
            return i;
        }
    }
    return -1;
}

//inserting edge between two vertices
int graph::insertEdge(char * firstLocation, char * secondLocation, char * roadName) {
    vertex * first = nullptr;
    vertex * second = nullptr;

    findVertex(firstLocation, first);
    findVertex(secondLocation, second);

    if (first && second) {
        return first -> addAdjacent(second, roadName);
    }

    return -1;
}

//displaying adjacent vertices given name
int graph::displayAdjacent(char * location) {
    vertex * displaying = nullptr;
    findVertex(location, displaying);

    return displayAdjacent(displaying);
}

//display adjacent vertices given specific vertex
int graph::displayAdjacent(vertex * displaying) {
    if (!displaying) return 0;

    int adjacent = displaying -> displayAdjacent();
    return adjacent;
}