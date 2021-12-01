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
    newGraph.insertEdge((char*) "C", (char*) "D", (char*) "seventh");

    newGraph.displayAll();

    int connected = newGraph.findConnected((char*) "A");
    cout << endl << "From A, you can visit " << connected - 1<< " other locations." << endl;

    connected = newGraph.findConnected((char*) "B");
    cout << endl << "From B, you can visit " << connected - 1<< " other locations." << endl;

    connected = newGraph.findConnected((char*) "C");
    cout << endl << "From C, you can visit " << connected - 1<< " other locations." << endl;

    connected = newGraph.findConnected((char*) "D");
    cout << endl << "From D, you can visit " << connected - 1<< " other locations." << endl;

    connected = newGraph.findConnected((char*) "E");
    cout << endl << "From E, you can visit " << connected - 1<< " other locations." << endl;

    return 0;
}