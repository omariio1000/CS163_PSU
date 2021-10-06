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

char* parseInput(char * in);

int main() {
  feed new_feed;

  bool running = true;

  while (running) {
	int answer = 0;
	cout << endl << "Would you like to:" << endl;
	cout << "1) Create a post" << endl;
	cout << "2) Make a comment" << endl;
	cout << "3) Like a post" << endl;
	cout << "4) Like a comment" << endl;
	cout << "5) Display entire feed" << endl;
	cout << "6) Display posts with a certain like count" << endl;
	cout << "7) Display all comments on a certain post" << endl;
	cout << "8) Remove a post" << endl;
	cout << "9) Quit" << endl << endl;

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

	  bool posted;
	  
	  if (!reposted) posted = new_feed.create_post(title, text, name, nullptr);
	  else {
		cout << endl << "What is the name of the orignal poster? ";
		cin.get(source, 1000, '\n');
		cin.clear();
		cin.ignore(100, '\n');
		source = parseInput(source);
		posted = new_feed.create_post(title, text, name, source);
	  }

	  if (posted) cout << endl << "The post was created successfully!" << endl;
	  else cout << endl << "Failed to post." << endl;
	  
	}
	
	else if (answer == 2) {//Make comment
	  
	}

	else if (answer == 3) {//Like post

	}

	else if (answer == 4) {//Like comment

	}

	else if (answer == 5) {//Display feed
	  bool displayed = new_feed.display_all();
	  if (!displayed) cout << endl << "Your feed is empty!" << endl;
	}

	else if (answer == 6) {//Display posts with certain like count

	}

	else if (answer == 7) {//Display comments on certain post

	}

	else if (answer == 8) {//Remove post
	  
	}
	
	else if (answer == 9) running = false;
	
	else cout << endl << "Invalid Response." << endl;
  }
  
  return 0;
}


char* parseInput(char * in) {
  char* parsed = new char[strlen(in) + 1];
  strcpy(in, parsed);
  return parsed;
}
