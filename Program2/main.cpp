/* Omar Nassar
 * Portland State University CS163
 * October 18, 2021
 * Test client for message board ADT
 */

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

#include "stack.h"
#include "queue.h"

using namespace std;

/*
//function to reduce char array sizes and save memory in ADT
char * parseInput(char * in) {
    //cout << endl << in << endl;
    char * parsed = new char[strlen(in) + 1];
    strcpy(parsed, in);
    //cout << endl << parsed << endl;
    delete[] in;
    return parsed;
}*/

int main() {
    queue new_queue;
    bool running_q = true; 

    while (running_q) {
        int answer;

        cout << endl << "1: Add a new server (enqueue)";
        cout << endl << "2: Remove the first server (dequeue)";
        cout << endl << "3: Display all servers";
        cout << endl << "4: Quit";
        cout << endl << "What would you like to do? ";
        cin >> answer;
        cin.clear();
        cin.ignore(100, '\n');

        if (answer == 1) {//Enqueue
            stack tempStack;
            char * serverName = new char[100];
            bool running_s = true;

            cout << endl << "Input the server name: ";
            cin.get(serverName, 100, '\n');
            cin.clear();
            cin.ignore(100, '\n');
            //serverName = parseInput(serverName);

            while (running_s) {
                int option;

                cout << endl << "1: Send a new message (push)";
                cout << endl << "2: Remove the latest message (pop)";
                cout << endl << "3: Display all messages in server";
                cout << endl << "4: End server";
                cout << endl << "What would you like to do? ";
                cin >> option;
                cin.clear();
                cin.ignore(100, '\n');


                if (option == 1) {//Push
                    char * name = new char[100];
                    char * text = new char[1000];

                    cout << endl << "Who is sending this message? ";
                    cin.get(name, 100, '\n');
                    cin.clear();
                    cin.ignore(100, '\n');
                    //name = parseInput(name);

                    cout << endl << "Insert the contents of the message: ";
                    cin.get(text, 1000, '\n');
                    cin.clear();
                    cin.ignore(1000, '\n');
                    //text = parseInput(text);

                    tempStack.push(name, text);

                    delete[] name;
                    delete[] text;
                    name = nullptr;
                    text = nullptr; 
                }

                else if (option == 2) {//Pop
                    tempStack.pop();
                }

                else if (option == 3) {//Display All
                    tempStack.display_all();
                }

                else if (option == 4) running_s = false; //End Server

                else cout << endl << "Invalid Input." << endl;
            }

            new_queue.enqueue(tempStack, serverName);
            tempStack.~stack();
            delete[] serverName;
            serverName = nullptr;
        }

        else if (answer == 2) {//Dequeue
            new_queue.dequeue();
        }

        else if (answer == 3) {//Display All
            new_queue.display_all();
        }

        else if (answer == 4) running_q = false; //Quit

        else cout << endl << "Invalid Input." << endl;
    }
    return 0;
}
