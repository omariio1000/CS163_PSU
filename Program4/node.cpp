/* Omar Nassar
 * Portland State University CS163
 * November 18, 2021
 * Node class implementation for vehicle storage in BST
 */

#include "node.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

node::node() {
    make = nullptr;
    model = nullptr;
    color = nullptr;
    information = nullptr;
    left = nullptr;
    right = nullptr;
}

node::~node() {
    delete[] make;
    delete[] model;
    delete[] color;
    delete[] information;

    if (left) delete left;
    if (right) delete right;
}

//adding data to a node
int node::addData(char * inMake, char * inModel, char * inColor, char * inInformation, int inYear, int inPrice, int inMileage) {
    if (!inMake |!inModel | !inColor | !inInformation) return 0;

    //copying over all strings

    make = new char[strlen(inMake) + 1];
    strcpy(make, inMake);

    model = new char[strlen(inModel) + 1];
    strcpy(model, inModel);

    color = new char[strlen(inColor) + 1];
    strcpy(color, inColor);

    information = new char[strlen(inInformation) + 1];
    strcpy(information, inInformation);

    year = inYear;
    price = inPrice;
    mileage = inMileage;
    return 1;
}

//adding data to a node if given another node (copy)
int node::addData(node * inData) {

    //copying over all strings from other node

    make = new char[strlen(inData -> make) + 1];
    strcpy(make, inData -> make);

    model = new char[strlen(inData -> model) + 1];
    strcpy(model, inData -> model);

    color = new char[strlen(inData -> model) + 1];
    strcpy(color, inData -> color);

    information = new char[strlen(inData -> information) + 1];
    strcpy(information, inData -> information);

    year = inData -> year;
    price = inData -> price;
    mileage = inData -> mileage;
    return 1;
}

//displaying data in a node
int node::display() {
    if (!make | !model | !color | !information) return 0;

    cout << endl << year << " " << make << " " << model << endl;
    cout << "Color: " << color << endl;
    cout << mileage << " miles" << endl;
    cout << "Notes: " << information << endl;
    cout << "Price: $" << price << endl;
    return 1;
}

int node:: displayPrice() {
    cout << endl << price << endl;
    return 1;
}

//returns true if node is greater than node comparing to
bool node::compare(node * comparing) {
    int comp = compare(comparing -> make, comparing -> model, comparing -> year);
    if (comp == 0 || comp == 1) return true;
    return false;
}

int node::compare(char * inMake, char * inModel, int inYear) {
    if (year > inYear) return 1;
    else if (year < inYear) return 2;

    else {//same year
        if (strcmp(make, inMake) > 0) return 1;
        else if (strcmp(make, inMake) < 0) return 2;

        else {//same make
            if (strcmp(model, inModel)) return 1;
            else if (strcmp(model, inModel)) return 2;
        }
    }
    
    //same exact make model and year
    return 0;
    
}
