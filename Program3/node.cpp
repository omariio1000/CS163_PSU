/* Omar Nassar
 * Portland State University CS163
 * November 1, 2021
 * ADT implementation for node class storing vehicle data
 */

#include "node.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

using namespace std;

node::node() {
    next = nullptr;
}

node::~node() {
    delete[] make;
    delete[] model;
    delete[] color;
    delete[] information;
    make = nullptr;
    model = nullptr;
    color = nullptr;
    information = nullptr;
    if (next) delete next;
    next = nullptr;
}

int node::addData(char * inMake, char * inModel, char * inColor, char * inInformation, int inYear, int inPrice, int inMileage) {
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

int node::addData(node * inData) {
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

int node::display() {
    if (!make | !model | !color | !information) return 0;

    cout << endl << year << " " << make << " " << model << endl;
    cout << "Color: " << color << endl;
    cout << mileage << " miles" << endl;
    cout << "Notes: " << information << endl;
    cout << "Price: $" << price << endl; 
    return 1;
}

int node::getPrice(int & outPrice) {
    outPrice = price;
    return 1;
}

int node::getMakeModel(char *& outMake, char *& outModel) {
    outMake = new char[strlen(make) + 1];
    strcpy(outMake, make);

    outModel = new char[strlen(model) + 1];
    strcpy(outModel, model);
    return 1;
}

bool node::compare(char * inMake, char * inModel) {
    if (strcmp(make, inMake) == 0 && strcmp(model, inModel) == 0) return true;
    return false;
}
