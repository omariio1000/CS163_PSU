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

                    cout << endl << "Insert the contents of the message: ";
                    cin.get(text, 1000, '\n');
                    cin.clear();
                    cin.ignore(1000, '\n');

                    //pushing data to stack object
                    if (tempStack.push(name, text) == 0) cout << endl << "Invalid Input." << endl;
                    else cout << endl << "Message pushed on stack." << endl;

                    delete[] name;
                    delete[] text;
                    name = nullptr;
                    text = nullptr; 
                }

                else if (option == 2) {//Pop
                    if (tempStack.pop() == 0) cout << endl << "Cannot Pop, Stack is Empty." << endl;
                    else cout << endl << "Latest message popped off stack." << endl;
                }

                else if (option == 3) {//Display All
                    if (tempStack.display_all() == 0) cout << endl << "Stack is Empty!" << endl;
                }

                else if (option == 4) running_s = false; //End Server

                else cout << endl << "Invalid Input." << endl;
            }

            //enqueueing stack item
            if (new_queue.enqueue(tempStack, serverName) == 0) cout << endl << "Invalid Server Name." << endl;
            else cout << endl << "Server enqueued." << endl;
            //deleting the temporary stack
            tempStack.~stack();
            delete[] serverName;
            serverName = nullptr;
        }

        else if (answer == 2) {//Dequeue
            if (new_queue.dequeue() == 0) cout << endl << "Cannot Dequeue, Queue is Empty." << endl;
            else cout << endl << "Sever dequeued." << endl;
        }

        else if (answer == 3) {//Display All
            if (new_queue.display_all() == 0) cout << endl << "Queue is Empty!" << endl;
        }

        else if (answer == 4) running_q = false; //Quit

        else cout << endl << "Invalid Input." << endl;
    }
    return 0;
}
