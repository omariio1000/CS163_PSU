/* Omar Nassar
 * Portland State University CS163
 * November 30, 2021
 * Implementation of vertex class for graph data structure
 */

#include "vertex.h"
#include "node.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

vertex::vertex(char * inLocation) {//constructor
    head = nullptr;
    if (inLocation) {
        location = new char[strlen(inLocation) + 1];
        strcpy(location, inLocation);
    }
}

vertex::~vertex() {//destructor
    if (location) delete location;
    location = nullptr;
    if (head) delete head;
    head = nullptr;
}

//compare char* to location and return true if match
bool vertex::compare(char * inLocation) {
    if (!inLocation) return false;
    if (strcmp(location, inLocation) == 0) return true;
    else return false;
}

//wrapper to add adjacent vertex (directional)
int vertex::addAdjacent(vertex * adding, char * roadName) {
    if (!adding) return 0;
    return addAdjacent(head, adding, roadName);
}

//recursive function to add adjacent vertex (directional)
int vertex::addAdjacent(node *& head, vertex * adding, char * roadName) {
    if (!head) {
        head = new node(roadName);
        head -> addAdjacent(adding);
        return 1;
    }
    return addAdjacent(head -> next, adding, roadName);
}

//displaying location name
bool vertex::displayLocation() {
    if (!location) return false;
    cout << location;
    return true;
}

//wrapper to display adjacent vertices
int vertex::displayAdjacent() {
    cout << endl;
    cout << location << ": ";
    int adjacent = displayAdjacent(head);
    cout << "There are " << adjacent << " connected locations." << endl;
    return adjacent;
}

//recursive function to display adjacent vertices
int vertex::displayAdjacent(node * head) {
    if (!head) {
        cout << endl;
        return 0;
    }

    if (head != this -> head) {
        cout << " -> ";
    }
    head -> displayAdjacent();

    return 1 + displayAdjacent(head -> next);
}