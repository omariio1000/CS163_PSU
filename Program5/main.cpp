/* Omar Nassar
 * Portland State University CS163
 * November 30, 2021
 * Test client for adjacency list graph data structure
 */

#include "graph.h"
#include "vertex.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    graph newGraph(5);

    newGraph.insertVertex((char*) "A");
    newGraph.insertVertex((char*) "B");
    newGraph.insertVertex((char*) "C");
    newGraph.insertVertex((char*) "D");
    newGraph.insertVertex((char*) "E");

    newGraph.insertEdge((char*) "A", (char*) "B", (char*) "first");
    newGraph.insertEdge((char*) "B", (char*) "E", (char*) "second");
    newGraph.insertEdge((char*) "B", (char*) "C", (char*) "third");
    newGraph.insertEdge((char*) "C", (char*) "A", (char*) "fourth");
    newGraph.insertEdge((char*) "D", (char*) "E", (char*) "fifth");
    newGraph.insertEdge((char*) "A", (char*) "D", (char*) "sixth");

    newGraph.displayAll();

    return 0;
}