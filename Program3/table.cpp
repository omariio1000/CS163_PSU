/* Omar Nassar
 * Portland State University CS163
 * November 1, 2021
 * ADT implementation for hashtable storing vehicles for sale
 */

#include "table.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

table::table() {
    priceTable = new node*[size];
    makeModelTable = new node*[size];
    for (int i = 0; i < size; i++) {
        priceTable[i] = nullptr;
        makeModelTable[i] = nullptr;
    }
}

table::~table() {
    for (int i = 0; i < size; i++) {
        if (priceTable[i]) {
            delete priceTable[i];
            priceTable[i] = nullptr;
        }
        if (makeModelTable[i]) {
            delete makeModelTable[i];
            makeModelTable[i] = nullptr;
        }
    }
    delete[] priceTable;
    priceTable = nullptr;

    delete[] makeModelTable;
    makeModelTable = nullptr;
}

int table::priceHash(int price) {
    return 0;
}

int table::makeModelHash(char * make, char * model) {
    return 0;
}

int table::addVehicle(int price, char * make, char * model, node * inData) {
    int priceIndex = priceHash(price);
    int makeModelIndex = makeModelHash(make, model);

    node * priceNode = priceTable[priceIndex];
    node * makeModelNode = makeModelTable[makeModelIndex];
    
    while (priceNode) priceNode = priceNode -> next;
    priceNode = new node;
    priceNode -> addData(inData);

    while(makeModelNode) makeModelNode = makeModelNode -> next;
    makeModelNode = new node;
    makeModelNode -> addData(inData);

    return 1;
}

int table::displayVehicle(char * inMake, char * inModel) {
    int index = makeModelHash(inMake, inModel);
    
    node * chain = makeModelTable(index);
    while (chain) {
        //write compare function for node
    }
    return 1;
}

int table::loadData(char * fileName) {
    return 0;
}

int table::removeVehicle(char * inMake, char * inModel) {
    return 0;
}

int table::retrieve(int lowestPrice, int highestPrice, node **& retrieved) {
    return 0;
}
