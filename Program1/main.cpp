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
	cout << "4) Display entire feed" << endl;
	cout << "5) Display posts with a certain like count" << endl;
	cout << "6) Display all comments on a certain post" << endl;
	cout << "7) Remove a post" << endl;
	cout << "8) Quit" << endl;
	cin >> answer;

	if (answer == 1) {
	  char * title;
	  char * text;
	  char * name;
	  char * source;
	  bool reposted = false;
	  cout << endl << "What is the title of the post? ";
	  cin >> title;
	  cout << endl << "Insert the contents of the post: ";
	  cin >> text;
	  cout << endl << "What is the name of the poster? ";
	  cin >> name;
	  cout << endl << "Is this content reposted? (1 for yes, 0 for no) ";
	  if (!reposted) new_feed.create_post(title, text, name, nullptr);
	  else {
		cout << endl << "What is the name of the orignal poster? ";
		cin >> source;
		new_feed.create_post(title, text, name, source);
	  }
	}
	
	else if (answer == 2) {

	}

	else if (answer == 3) {

	}

	else if (answer == 4) {

	}

	else if (answer == 5) {

	}

	else if (answer == 6) {

	}

	else if (answer == 7) {

	}

	else if (answer == 8) running = false;
	
	else cout << endl << "Invalid Response." << endl;
  }
  
  return 0;
}
