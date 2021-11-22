/* Omar Nassar
 * Portland State University CS163
 * November 18, 2021
 * Implementation of BST that stores vehicles and their info
 */

#include "tree.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

tree::tree() {
    root = nullptr;
}

tree::~tree() {
    delete root;
}

int tree::addVehicle(node * inData) {
    return addVehicle(root, inData);
}

int tree::addVehicle(node * root, node * inData) {
    if (!root) {
        root = new node;
        root -> addData(inData);
        return 1;
    }
    if (inData -> compare(root)) return addVehicle(root -> right, inData);
    return addVehicle(root -> left, inData); 
}

int tree::remove(char * inMake, char * inModel, int inYear) {
    if (!root) return 0;
    return remove(inMake, inModel, inYear, root);
}

node * inOrderSuccessor(node * root) {
    if (!root -> left) {//furthest to the left on subtree
        node * temp = root;
        if (root -> right) {
            root = root -> right;
        }
        else {
            root = nullptr;
        }
        temp -> left = nullptr;
        temp -> right = nullptr;
        return temp;
    }
    else return inOrderSuccessor(root -> left);
}

int tree::remove(char * inMake, char * inModel, int inYear, node * root) {
    if (!root) return 1;
    int comp = root -> compare(inMake, inModel, inYear);
    if (comp == 0) {//delete
        if (!root -> right && !root -> left) {
            delete root;
            root = nullptr;
        }
        else if (!root -> right) {
            node * temp = root;
            root = root -> left;
            temp -> left = nullptr;
            delete temp;
        }
        else if (!root -> left) {
            node * temp = root;
            root = root -> right;
            temp -> right = nullptr;
            delete temp;
        }
        else {//two children
            node * temp = root;
            root = inOrderSuccessor(root -> right);
            root -> right = temp -> right;
            root -> left = temp -> left;
            temp -> left = temp -> right = nullptr;
            delete temp;
        }
        //go through and check subtree again
        return remove(inMake, inModel, inYear, root);
    }
    if (comp == 1) {//greater
        return remove(inMake, inModel, inYear, root -> right);
    }
    if (comp == 2) {//less
        return remove(inMake, inModel, inYear, root -> left);
    }
    return 0;
}

int tree::height() {
    if (!root) return 0;
    return height(root);
}

int tree::height(node * root) {
    if (!root) return -1;

    int lHeight = height(root -> left);
    int rHeight = height(root -> right);

    if (lHeight > rHeight) return lHeight + 1;
    return rHeight + 1;
}

int tree::efficiency() {
    if (!root) return 9999;
   
    int lHeight = height(root -> left);
    int rHeight = height(root -> right);

    return lHeight - rHeight;
}

//loading data from file
int tree::loadData(char * fileName) {
    if (!fileName) return -1;
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

            //memset because otherwise char array was full of junk
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

                    //memset because otherwise char array was full of junk
                    memset(allInfo[counter], 0, 1000);
                }
            }
            int year = atoi(allInfo[2]);
            int price = atoi(allInfo[4]);
            int mileage = atoi(allInfo[5]);

            //make a new node with data from line
            node * adding = new node;
            adding -> addData(allInfo[0], allInfo[1], allInfo[3], allInfo[6], year, price, mileage);

            //add node to tree
            addVehicle(adding);

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

            //memset again because array was full of junk
            memset(line, 0, 10000);
        }
        delete[] line; 
        delete[] allInfo;
    }
    else {
        file.close();
        return 0;
    }

    file.close();
    return 1;
}
