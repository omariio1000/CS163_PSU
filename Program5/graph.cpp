/* Omar Nassar
 * Portland State University CS163
 * November 30, 2021
 * Implementation of adjacency list class for graph data structure
 */

#include "graph.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

graph::graph(int size) {
    adjacencyList = new vertex*[size];
    for (int i = 0; i < size; i++) adjacencyList(i) = nullptr;
    list_size = size;
}

graph::~graph() {
    for (int i = 0; i < list_size; i++) {
        if (adjacencyList[i]) {
            delete adjacencyList[i];
            adjacencyList[i] = nullptr;
        }
    }
    delete[] adjacencyList;
    adjacencyList = nullptr;
}
