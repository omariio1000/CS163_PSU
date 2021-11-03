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
#include <cstdio>

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

    node * chain = makeModelTable[index];
    while (chain) {
        if (chain -> compare(inMake, inModel)) chain -> display();
        chain = chain -> next;
    }
    return 1;
}

int table::loadData(char * fileName) {
    ifstream file;
    file.open(fileName);
    if (file) {
        while (!file.eof()) {
            char * line = new char[10000];
            file.getline(line, 10000);
            //cout << endl << line << endl;
            //cout << strlen(line) << endl;;
            char ** allInfo = new char*[7];
            allInfo[0] = new char[1000];
            int counter = 0;
            int pos = 0;
            for (int i = 0; i < (int) strlen(line); i++) {
                if (line[i] != '|') {
                    allInfo[counter][pos] = line[i];
                    pos++;
                }
                else {
                    pos++;
                    allInfo[counter][pos] = '\0';
                    counter++;
                    pos = 0;
                    allInfo[counter] = new char[1000];
                }
            }
            allInfo[counter][pos + 1] = '\0';

            int year = atoi(allInfo[2]);
            int price;
            int mileage;

            node * adding = new node;
            adding -> addData(allInfo[0], allInfo[1], allInfo[3], allInfo[6], year, price, mileage);

            addVehicle(price, allInfo[0], allInfo[1], adding);
            /*for (int i = 0; i < 7; i++) {
                cout << endl << allInfo[i] << endl;
            }*/
        }
    }

    file.close();
    return 0;
}

int table::removeVehicle(char * inMake, char * inModel) {
    int makeModelIndex = makeModelHash(inMake, inModel);

    node * found = makeModelTable[makeModelIndex];

    while (found) {
        if (found -> compare(inMake, inModel)) {
            node * temp = found;
            found = found -> next;
            temp -> next = nullptr;
            delete temp;
            temp = nullptr;

            int price = 0;
            found -> getPrice(price);
            int priceIndex = priceHash(price);

            node * priceFound = priceTable[priceIndex];

            while (priceFound) {
                if (priceFound -> compare(inMake, inModel)) {
                    temp = priceFound;
                    priceFound = priceFound -> next;
                    temp -> next = nullptr;
                    delete temp;
                    temp = nullptr;
                }
                else priceFound = priceFound -> next;
            }

        }
        else found = found -> next;
        return 1;
    }
    return 0;
}

int table::retrieve(int lowestPrice, int highestPrice, node **& retrieved) {
    return 0;
}
