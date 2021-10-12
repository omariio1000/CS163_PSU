/*Omar Nassar
 *Portland State University CS163
 *October 1, 2021
 *Test client for social media feed ADT
 */

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

#include "posts_comments.h"

using namespace std;

//function to parse text input
char* parseInput(char * in);

//function to interpret errors returned from ADT implementation
void returnError(int in);

int main() {
    feed new_feed;

    bool running = true;

    while (running) {//loop to continue prompting user until quit
        int answer = 0;

        cout << endl << "1) Create a post" << endl;
        cout << "2) Make a comment" << endl;
        cout << "3) Like a post" << endl;
        cout << "4) Like a comment" << endl;
        cout << "5) Display entire feed" << endl;
        cout << "6) Display posts with a certain like count" << endl;
        cout << "7) Display all comments on a certain post" << endl;
        cout << "8) Remove a post" << endl;
        cout << "9) Quit" << endl;
        cout << "What would you like to do? ";

        cin >> answer;
        cin.clear();
        cin.ignore(100, '\n');

        if (answer == 1) {//Create post
            char* title = new char[1000];
            char* text = new char[1000];
            char* name = new char[1000];
            char* source = new char[1000];
            bool reposted = false;

            cout << endl << "What is the title of the post? ";
            cin.get(title, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');
            title = parseInput(title);

            cout << endl << "Insert the contents of the post: ";
            cin.get(text, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');
            text = parseInput(text);

            cout << endl << "What is the name of the poster? ";
            cin.get(name, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');
            name = parseInput(name);

            cout << endl << "Is this content reposted? (1 for yes, 0 for no) ";
            cin >> reposted;
            cin.clear();
            cin.ignore(100, '\n');

            if (!reposted) returnError(new_feed.create_post(title, text, name, nullptr));
            else {
                cout << endl << "What is the name of the orignal poster? ";
                cin.get(source, 1000, '\n');
                cin.clear();
                cin.ignore(100, '\n');
                source = parseInput(source);
                returnError(new_feed.create_post(title, text, name, source));
            }


        }

        else if (answer == 2) {//Make comment
            char * title = new char[1000];
            char * name = new char[1000];
            char * text = new char[1000];

            cout << endl << "What post would you like to comment on? ";
            cin.get(title, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');
            title = parseInput(title);

            cout << endl << "Who is leaving this comment? ";
            cin.get(name, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');
            name = parseInput(name);

            cout << endl << "Insert the contents of the comment: ";
            cin.get(text, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');
            text = parseInput(text);

            returnError(new_feed.create_comment(title, name, text));

        }

        else if (answer == 3) {//Like post
            char * title = new char[1000];

            cout << endl << "What post do you want to like?" << endl;
            cin.get(title, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            returnError(new_feed.like_post(parseInput(title)));
        }

        else if (answer == 4) {//Like comment
            char * title = new char[1000];
            char * name = new char[1000];

            cout << endl << "What is the name of the post this was commented on? ";
            cin.get(title, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');
            title = parseInput(title);

            cout << endl << "What is the commenter's name? ";
            cin.get(name, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');
            name = parseInput(name);

            returnError(new_feed.like_comment(title, name));  
        }

        else if (answer == 5) {//Display feed
            returnError(new_feed.display_all());
        }

        else if (answer == 6) {//Display posts with certain like count
            int likes;
            cout << endl << "Insert a minimum like count to display: ";
            cin >> likes;
            cin.clear();
            cin.ignore(100, '\n');
            returnError(new_feed.display_by_likes(likes));
        }

        else if (answer == 7) {//Display comments on certain post
            char * title = new char[1000];

            cout << endl << "What post would you like to view the comments of? ";
            cin.get(title, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');

            returnError(new_feed.display_comments(parseInput(title)));
        }

        else if (answer == 8) {//Remove post
            char * title = new char[1000];
            bool confirm;

            cout << endl << "What post would you like to delete? ";
            cin.get(title, 1000, '\n');
            cin.clear();
            cin.ignore(100, '\n');


            int results = new_feed.display_comments(title);
            returnError(results);

            if (results == -1 || 11) {
                cout << endl << "Are you sure you would like to delete this post? (1 for yes, 0 for no) ";
                cin >> confirm;
                cin.clear();
                cin.ignore(100, '\n');
                returnError(new_feed.remove_post(title));
            }
        }

        else if (answer == 9) running = false;

        else cout << endl << "Invalid Response." << endl;
    }

    return 0;
}

//function to reduce char array sizes and save memory in ADT
char* parseInput(char * in) {
    //cout << endl << in << endl;
    char* parsed = new char[strlen(in) + 1];
    strcpy(parsed, in);
    //cout << endl << parsed << endl;
    return parsed;
}

//function to process error codes given by implementation
void returnError(int in) {
    if (in == 0) cout << endl << "Post created successfully!" << endl;
    if (in == 1) cout << endl << "Comment created successfully!" <<endl;
    if (in == 2) cout << endl << "Post deleted successfully." << endl;
    if (in == 3) cout << endl << "Your feed is empty!" << endl;
    if (in == 4) cout << endl << "No post found with that title." << endl;
    if (in == 5) cout << endl << "No comment found by given person." << endl;
    if (in == 6) cout << endl << "No posts found with given like count" << endl;
    if (in == 7) cout << endl << "Invalid Input." << endl;
    if (in == 8) cout << endl << "Liked post!" << endl;
    if (in == 9) cout << endl << "Liked comment!" << endl;
    if (in == 10) cout << endl << "Unknown Error." << endl;
    if (in == 11) cout << endl << "There are no comments on this post." << endl;
}
