/* Omar Nassar
 * Portland State University CS163
 * November 1, 2021
 * HashTable ADT to store cars and their information
 */

#ifndef table_h
#define table_h

#include "node.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>

const int size = 21;

class table {
    public:
        //constructor and destructor
        table();
        ~table();

        //function to add vehicle to table
        int addVehicle(int price, char * make, char * model, node * inData);

        //function to display information of vehicle
        int displayVehicle(char * inMake, char * inModel);

        //display all
        int displayAll();

        //function to load data from file
        int loadData(char * fileName);

        //function to remove vehicle
        int removeVehicle(char * inMake, char * inModel);

        //retrive vehicle for price range
        int retrieve(int lowPrice, int highPrice, node **& retrieved);

    private:
        //hash function to generate index using price
        int priceHash(int price);

        //hash function to generate index using make and model
        int makeModelHash(char * make, char * model);

        //hash table using price to index
        node ** priceTable;

        //hash table using make and model to index
        node ** makeModelTable;
};

#endif
