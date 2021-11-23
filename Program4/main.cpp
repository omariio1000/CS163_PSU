/* Omar Nassar
 * Portland State University CS163
 * November 22, 2021
 * Test program for binary search tree storing vehicle listings
 */

#include "node.h"
#include "tree.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    tree newTree;
    bool running = true;

    while(running) {
        int answer;
        cout << endl << "1. Load data from a file" << endl;
        cout << "2. Manually add vehicle" << endl;
        cout << "3. Display all" << endl;
        cout << "4. Remove vehicle" << endl;
        cout << "5. Retrieve vehicle" << endl;
        cout << "6. Display Tree Height" << endl;
        cout << "7. Determine Tree Efficiency" << endl;
        cout << "8. Display Price Range (Low to High)" << endl;
        cout << "9. Quit" << endl;
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

            int result = newTree.loadData(fileName);
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
            else newTree.addVehicle(car);

            delete[] make;
            delete[] model;
            delete[] color;
            delete[] information;
            delete car;
        }

        else if (answer == 3) {//display all
            int count = newTree.displayAll();
            if (count == 0) cout << endl << "The tree is empty!" << endl;
        }

        else if (answer == 4) {//remove vehicle
            char * make = new char[100];
            char * model = new char[100];
            int year;

            cout << endl << "What is the make of the car?" << endl << ">> ";
            cin.get(make, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the model of the car?" << endl << ">> ";
            cin.get(model, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What year was this car made?" << endl << ">> ";
            cin >> year;
            cin.clear();
            cin.ignore(100, '\n');


            int result = newTree.remove(make, model, year);
            if (result == -1) cout << endl << "Invalid Input." << endl;
            else if (result == 0) cout << endl << "No vehicle matches make and model." << endl;

            delete[] make;
            delete[] model;
        }

        else if (answer == 5) {//retrieve vehicle
            char * make = new char[100];
            char * model = new char[100];
            int year;
            char multiple;

            cout << endl << "What is the make of the car?" << endl << ">> ";
            cin.get(make, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What is the model of the car?" << endl << ">> ";
            cin.get(model, 100);
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "What year was this car made?" << endl << ">> ";
            cin >> year;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Would you like to view multiple matches? (y/n)" << endl << ">> ";
            cin >> multiple;
            cin.clear();
            cin.ignore(100, '\n');

            if (multiple == 'y') {
                node ** retrieve = new node *[1000];
                for (int i = 0; i < 1000; i++) retrieve[i] = nullptr;
                
                int result = newTree.retrieve(make, model, year, retrieve, false);
                if (result == -1) cout << endl << "The tree is empty!" << endl;
                else if (result == 0) cout << endl << "No results were found" << endl;
                else {
                    cout << endl << "There were " << result << " matches." << endl;
                    cout << "Would you like to view your results? (y/n)" << endl << ">> ";

                    char yesno;
                    cin >>yesno;
                    cin.clear();
                    cin.ignore(100, '\n');

                    if (yesno == 'y') {
                        for (int i = 0; i < 1000; i++)
                        {
                            if (!retrieve[i]) i = 1000;
                            else {
                                retrieve[i] -> display();
                            }
                        }
                        
                    }
                }
                for (int i = 0; i < 1000; i++) if (retrieve[i]) delete retrieve[i];
                delete[] retrieve;
            }
            else if (multiple == 'n') {
                node ** retrieve = new node *[1];
                retrieve[0] = nullptr;
                int result = newTree.retrieve(make, model, year, retrieve, false);
                if (result == -1) cout << endl << "The tree is empty!" << endl;
                else if (result == 0) cout << endl << "No match was found" << endl;
                else {
                    cout << endl << "Would you like to view your result? (y/n)" << endl << ">> ";
                    char yesno;
                    cin >>yesno;
                    cin.clear();
                    cin.ignore(100, '\n');

                    if (yesno == 'y') retrieve[0] -> display();

                    delete retrieve[0];
                    delete[] retrieve;
                }
            }
            else cout << endl << "Invalid Input." << endl;

            delete[] make;
            delete[] model;
        }

        else if (answer == 6) {//display tree height
            int height = newTree.height();
            if (height == -1) cout << endl << "The tree is empty!" << endl;
            else cout << endl << "Tree height: " << height << endl;
        }

        else if (answer == 7) {//tree efficiency
            int balance = newTree.efficiency();
            if (balance == 9999) cout << endl << "Either your tree is really unbalanced or it's empty!" << endl;
            else if (balance == 0 || balance == 1 || balance == -1) 
                cout << endl << "Your tree is balanced and the balance factor is: " << balance << endl;
            else cout << endl << "Your tree is unbalanced and the balance factor is: " << balance << endl;
        }

        else if (answer == 8) {//price range
            if (newTree.priceRange() == 0) cout << endl << "The tree is empty!" << endl;
        }

        else if (answer == 9) running = false;        

        else cout << endl << "Invalid Input." << endl;
    }
}
