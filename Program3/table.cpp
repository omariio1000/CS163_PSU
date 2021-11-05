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
#include <cmath>
#include <vector>

using namespace std;

table::table() {//constructor
    //priceTable = new node*[size];
    makeModelTable = new node*[size];
    for (int i = 0; i < size; i++) {
        //priceTable[i] = nullptr;
        makeModelTable[i] = nullptr;
    }
}

table::~table() {//destructor
    for (int i = 0; i < size; i++) {
        /*if (priceTable[i]) {
            delete priceTable[i];
            priceTable[i] = nullptr;
        }*/
        if (makeModelTable[i]) {
            delete makeModelTable[i];
            makeModelTable[i] = nullptr;
        }
    }
    //delete[] priceTable;
    //priceTable = nullptr;

    delete[] makeModelTable;
    makeModelTable = nullptr;
}

/*int table::priceHash(int price) {
    int index;
    index = price/10000;
    return index % size;
}*/

//hash function with make and model
int table::makeModelHash(char * make, char * model) {
    int index = 0;
    
    index += make[0];
    index += model[strlen(model) - 1];
    index = (int) pow(index, 2);
    return index % size;
}

//adding a vehicle
int table::addVehicle(char * make, char * model, node * inData) {
    //int priceIndex = priceHash(price);
    int makeModelIndex = makeModelHash(make, model);
    
    /*if (!priceTable[priceIndex]) {
        priceTable[priceIndex] = new node;
        priceTable[priceIndex] -> addData(inData);
    }
    else {
        node * adding = priceTable[priceIndex];
        while (adding -> next)
            adding = adding -> next;
        adding -> next = new node;
        adding -> next -> addData(inData);
    }*/

    if (!makeModelTable[makeModelIndex]) {//index is empty
        makeModelTable[makeModelIndex] = new node;
        makeModelTable[makeModelIndex] -> addData(inData);
    }
    else {//chaining for collision
        node * adding = makeModelTable[makeModelIndex];
        while (adding -> next)
            adding = adding -> next;
        adding -> next = new node;
        adding -> next -> addData(inData);
    }
    
    return 1;
}

//displaying vehicle with certain model or make
int table::displayVehicle(char * inMake, char * inModel) {
    int index = makeModelHash(inMake, inModel);

    node * chain = makeModelTable[index];
    while (chain) {
        if (chain -> compare(inMake, inModel)) chain -> display();
        chain = chain -> next;
    }
    return 1;
}

//displaying entire table with index and chain
int table::displayAll() {
    for (int i = 0; i < size; i++) {
        if (makeModelTable[i]) {
            node * displaying = makeModelTable[i];
            int chain = 0;
            while (displaying) {
                cout << endl << "Index: " << i << " Chain: " << chain;
                displaying -> display();
                displaying = displaying -> next;
                chain++;
            }
            delete displaying;
            displaying = nullptr;
        }
    }
    return 1;
}

//loading data from file
int table::loadData(char * fileName) {
    ifstream file;
    file.open(fileName);
    if (file) {
        char * line = new char[10000];
        char ** allInfo = new char*[7];

        //simultaneously check if next line exists and get line if it does
        while (file.getline(line, 10000)) {
            //cout << endl << line << endl;
            //cout << strlen(line) << endl;;
            allInfo[0] = new char[1000];
            memset(allInfo[0], 0, sizeof(allInfo));
            int counter = 0;
            int pos = 0;
            for (int i = 0; i < (int) strlen(line); i++) { 
                if (line[i] != '|' && line[i] != '\r') {
                    allInfo[counter][pos] = line[i];
                    pos++;
                }
                else if (line[i] != '\r'){
                    pos++;
                    counter++;
                    pos = 0;
                    allInfo[counter] = new char[1000];
                    memset(allInfo[counter], 0, 1000);
                }
            }
            int year = atoi(allInfo[2]);
            int price = atoi(allInfo[4]);
            int mileage = atoi(allInfo[5]);

            //make a new node with data from line
            node * adding = new node;
            adding -> addData(allInfo[0], allInfo[1], allInfo[3], allInfo[6], year, price, mileage);

            //add node to table
            addVehicle(allInfo[0], allInfo[1], adding);

            /*for (int i = 0; i < 7; i++) {
                cout << endl << allInfo[i] << endl;
            }*/

            //freeing up memory and resetting it
            //(had errors with just deleting and not memsetting)
            delete adding;
            adding = nullptr;

            for (int i = 0; i < 7; i++) {
                delete[] allInfo[i];
                allInfo[i] = nullptr;
            }
            delete[] line;
            line = new char[10000];
            memset(line, 0, 10000);
        }
        delete[] line; 
        delete[] allInfo;
    }

    file.close();
    return 0;
}

//removing vehicle by make and model
int table::removeVehicle(char * inMake, char * inModel) {
    int index = makeModelHash(inMake, inModel);
    if (!makeModelTable[index]) return 0;

    if (makeModelTable[index] -> compare(inMake, inModel)) {//if no need for recursion
        node * temp = makeModelTable[index] -> next;
        makeModelTable[index] -> next = nullptr;
        delete makeModelTable[index];
        makeModelTable[index] = temp;
        return 1;
    }

    else return removeVehicle(makeModelTable[index] -> next, makeModelTable[index], inMake, inModel);
}

//recursive function to delete in chain
int table::removeVehicle(node * deleting, node * previous, char * inMake, char * inModel) {
    if (!deleting) return 0;
    if (deleting -> compare(inMake, inModel)) {
        previous -> next = deleting -> next;
        deleting -> next = nullptr;
        delete deleting;
        return 1;
    }
    return removeVehicle(deleting -> next, deleting, inMake, inModel);
}

//retrieving within price range
int table::retrieve(int lowestPrice, int highestPrice, node **& retrieved) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (makeModelTable[i]) {
            node * checking = makeModelTable[i];
            while (checking) {
                if (checking -> checkPrice(lowestPrice, highestPrice)) {
                   retrieved[counter] = new node;
                   retrieved[counter] -> addData(checking);
                   counter += 1;
                }
                checking = checking -> next;
            }
            delete checking; 
            checking = nullptr;
        }
    }
    return 1;
}
