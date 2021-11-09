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
#include <vector>

using namespace std;

int main() {
    table newTable;
    bool running = true;
    while (running) {
        int answer;
        cout << endl << "1. Load data from a file" << endl;
        cout << "2. Manually add vehicle" << endl;
        cout << "3. Display all" << endl;
        cout << "4. Display by Make and Model" << endl;
        cout << "5. Remove vehicle" << endl;
        cout << "6. Retrieve vehicles within price range" << endl;
        cout << "7. Quit" << endl;
        cout << "What would you like to do?" << endl;
        cout << ">> ";

        cin >> answer;
        cin.clear();
        cin.ignore(1000, '\n');

        if (answer == 1) {//load from file
            char * fileName = new char[100];
            cout << endl << "What is the name of your file?" << endl << ">> ";

            cin.get(fileName, 100);
            cin.clear();
            cin.ignore(100, '\n');

            int result = newTable.loadData(fileName);
            if (result == -1) cout << endl << "Invalid Input." << endl;
            else if (result == 0) cout << endl << "There is no file with that name." << endl;
            delete[] fileName;
        }

        else if (answer == 2) {//add manually
            char * make = new char[100];
            char * model = new char[100];
            char * color = new char[100];
            char * information = new char[1000];
            int year;
            int price;
            int mileage;

            cout << endl << "What is the make of the car?" << endl << ">> ";
            cin.get(make, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the model of the car?" << endl << ">> ";
            cin.get(model, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the color of the car?" << endl << ">> ";
            cin.get(color, 100);
            cin.clear();
            cin.ignore(100, '\n');


            cout << endl << "What is the price of the car?" << endl << ">> ";
            cin >> price;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What year was this car made?" << endl << ">> ";
            cin >> year;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the mileage of this car?" << endl << ">> ";
            cin >> mileage;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What other information do you have (title, condition, etc.)?" << endl << ">> ";
            cin.get(information, 1000);
            cin.clear();
            cin.ignore(1000, '\n');

            node * car = new node;
            int result = car -> addData(make, model, color, information, year, price, mileage);
            if (result == 0) cout << endl << "Invalid Input." << endl;
            else newTable.addVehicle(make, model, car);

            delete[] make;
            delete[] model;
            delete[] color;
            delete[] information;
            delete car;
        }

        else if (answer == 3) {//display all
            if (!newTable.displayAll()) cout << endl << "There are no vehicles in the table." << endl;
        }

        else if (answer == 4) {//display by make/model
            char * make = new char[100];
            char * model = new char[100];

            cout << endl << "What is the make of the car?" << endl << ">> ";
            cin.get(make, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the model of the car?" << endl << ">> ";
            cin.get(model, 100);
            cin.clear();
            cin.ignore(100, '\n');

            int result = newTable.displayVehicle(make, model);
            if (result == 2) cout << endl << "No vehicle matches make and model." << endl;
            else if (result == 0) cout << endl << "Invalid Input." << endl;

            delete[] make;
            delete[] model;
        }

        else if (answer == 5) {//remove vehicle
            char * make = new char[100];
            char * model = new char[100];

            cout << endl << "What is the make of the car?" << endl << ">> ";
            cin.get(make, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the model of the car?" << endl << ">> ";
            cin.get(model, 100);
            cin.clear();
            cin.ignore(100, '\n');

            int result = newTable.removeVehicle(make, model);
            if (result == -1) cout << endl << "Invalid Input." << endl;
            else if (result == 0) cout << endl << "No vehicle matches make and model." << endl;

            delete[] make;
            delete[] model;
        }

        else if (answer == 6) {//retrieve within price range
            node ** retrieving = new node*[1000];
            for (int i = 0; i < 1000; i++) retrieving[i] = nullptr;
            int low;
            int high;

            cout << endl << "What is the lowest price?" << endl << ">> ";
            cin >> low;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the highest price?" << endl << ">> ";
            cin >> high;
            cin.clear();
            cin.ignore(100, '\n');

            int result = newTable.retrieve(low, high, retrieving);

            if (result == -1) cout << endl << "The low price is higher than the high price." << endl;
            else if (result == 0) cout << endl << "No vehicles were found in the given range." << endl;
            else {
                char yesno;
                cout << endl << "Would you like to view what you retrieved? (y/n)" << endl << ">> ";
                cin >> yesno;
                cin.clear();
                cin.ignore(100, '\n');
                if (yesno == 'y') {
                    for (int i = 0; i < 1000; i++) {
                        if (retrieving[i]) retrieving[i] -> display();
                        else break;
                    }
                }
                for (int i = 0; i < 1000; i++) {
                    if (retrieving[i]) delete retrieving[i];
                    else break;
                }
            }
            delete[] retrieving;
        }

        else if (answer == 7) running = false;

        else cout << endl << "Invalid Input." << endl;
    }
    return 0;
}
