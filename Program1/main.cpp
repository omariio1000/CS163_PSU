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

	  int result = new_feed.create_comment(title, name, text);

	  if (result == 0) cout << endl << "Comment created successfully!" << endl;
	  else if (result == 1) cout << endl << "Your feed is empty!" << endl;
	  else if (result == 2) cout << endl << "Invalid Input." << endl;
	  else if (result == 3) cout << endl << "No post was found with that title." << endl;
	}

	else if (answer == 3) {//Like post
	  char * title = new char[1000];
	  
	  cout << endl << "What post do you want to like?" << endl;
	  cin.get(title, 1000, '\n');
	  cin.clear();
	  cin.ignore(100, '\n');

	  int liked = new_feed.like_post(parseInput(title));
	  if (liked == 1) cout << endl << "Your feed is empty!" << endl;
	  else if (liked == 2) cout << endl << "Could not find a post with that title." << endl;
	  else cout << endl << "Liked post." << endl;
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

	  int result = new_feed.like_comment(title, name);
	  if (result == 0) cout << endl << "Liked comment." << endl;
	  else if (result == 1) cout << endl << "Your feed is empty!" << endl;
	  else if (result == 2) cout << endl << "Could not find a post with that title." << endl;
	  else if (result == 3) cout << endl << "Could not find a comment by " << name << " on this post." << endl;
	  
	}

	else if (answer == 5) {//Display feed
	  bool displayed = new_feed.display_all();
	  if (!displayed) cout << endl << "Your feed is empty!" << endl;
	}

	else if (answer == 6) {//Display posts with certain like count
	  int likes;
	  cout << endl << "Insert a minimum like count to display: ";
	  cin >> likes;
	  cin.clear();
	  cin.ignore(100, '\n');
	  int result = new_feed.display_by_likes(likes);
	  if (result == 1) cout << endl << "Your feed is empty!" << endl;
	  if (result == 2) cout << endl << "Could not find any posts that meet the required like count." << endl;
	}

	else if (answer == 7) {//Display comments on certain post
	  char * title = new char[1000];
	  
	  cout << endl << "What post would you like to view the comments of? ";
	  cin.get(title, 1000, '\n');
	  cin.clear();
	  cin.ignore(100, '\n');

	  int displayed = new_feed.display_comments(parseInput(title));
	  if (displayed == 1) cout << endl << "Your feed is empty!" << endl;
	  if (displayed == 2) cout << endl << "Could not find a post with that title." << endl;
	  else if (displayed == 3) cout << endl << "There are no comments on this post." << endl;
	}

	else if (answer == 8) {//Remove post
	  char * title = new char[1000];
	  bool confirm;

	  cout << endl << "What post would you like to delete? ";
	  cin.get(title, 1000, '\n');
	  cin.clear();
	  cin.ignore(100, '\n');

	  int results = new_feed.display_comments(title);
	  if (results == 1) cout << endl << "Your feed is empty!" << endl;
	  else if (results == 2) cout << endl << "Could not find a post with that title." << endl;
	  else {
		cout << endl << "Are you sure you would like to delete this post? (1 for yes, 0 for no) ";
		cin >> confirm;
		cin.clear();
		cin.ignore(100, '\n');
		results = new_feed.remove_post(title);
		if (results == 0) cout << endl << "Post was deleted successfully." << endl;
	  }
	}
	
	else if (answer == 9) running = false;
	
	else cout << endl << "Invalid Response." << endl;
  }
  
  return 0;
}


char* parseInput(char * in) {
  //cout << endl << in << endl;
  char* parsed = new char[strlen(in) + 1];
  strcpy(parsed, in);
  //cout << endl << parsed << endl;
  return parsed;
}
