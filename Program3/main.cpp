/* Omar Nassar
 * Portland State University CS163
 * November 1, 2021
 * Test client for hash table that stores vehicle information
 */

#include "node.h"
#include "table.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    table newTable;
    char * title = new char[9];
    strcpy(title, "cars.txt");
    newTable.loadData(title);
    newTable.displayAll();
    char * make = new char[10];
    char * model = new char[25];
    strcpy(make, "Ford");
    strcpy(model, "F-350 Super Duty");
    newTable.removeVehicle(make, model);
    cout << endl << "REMOVED" << endl;
    newTable.displayAll();
    cout << endl << "RETRIEVED" << endl;
    table retrieved;
    newTable.retrieve(10000, 250000, retrieved);
    return 0;
}
