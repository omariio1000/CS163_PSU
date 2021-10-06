/*Omar Nassar
 *Portland State University CS163
 *October 1, 2021
 *Functions associated with ADT for social media feed
 */

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

#include "posts_comments.h"

using namespace std;

feed::feed() {//default constructor
  head = nullptr;
}

feed::~feed() {//destructor
  post_node * temp = nullptr;

  while (head) {
	temp = head -> next_post;
	comment_node * temp_comment = nullptr;

	if (temp) while (temp -> comment_head) {
	  temp_comment = temp -> comment_head -> next_reply;
	  delete temp -> comment_head;
	  temp -> comment_head = temp_comment;
	}

	temp = head -> next_post;
	delete head;
	head = temp;
	
  }
  
  head = nullptr;
}

post_node* locatePost(char * inTitle, post_node * post) {
  if (!post) return nullptr;
  if (strcmp(inTitle, post -> title) == 0) return post;
  else return locatePost(inTitle, post -> next_post);
}

bool feed::create_post(char * inTitle, char * inText, char * inName, char * inSource) {
  //cout << endl << inTitle << endl << inText << endl << inName << endl << inSource << endl;
  return create_post(inTitle, inText, inName, inSource, head);
}

bool feed::create_post(char * inTitle, char * inText, char * inName, char * inSource, post_node *& post) {
  if (!post) {
	//cout << endl << "Post being created." << endl;
	post = new post_node();
	post -> title = inTitle;
	post -> text = inText;
	post -> name = inName;
	post -> source = inSource;
	return true;
  }
  else {
	//cout << endl << "Calling recursively." << endl;
	return create_post(inTitle, inText, inName, inSource, post -> next_post);	
  }
  return false;
}

bool feed::display_all() {  
  if (!head) return false;
  post_node * temp_post = head;
  while (temp_post) {
	comment_node * temp_comment = temp_post -> comment_head;
	cout << endl << temp_post -> title << endl;
	cout << "Posted by " << temp_post -> name << endl;
	if (temp_post -> source) cout << "Reposted from " << temp_post -> source << endl;
	cout << endl << temp_post -> text << endl;
	cout << temp_post -> likes << " likes" << endl;

	if (temp_comment) cout << endl << "Comments:" << endl;
	while (temp_comment) {
	  cout << endl << temp_comment -> name << " says:" <<endl;
	  cout << temp_comment -> text << endl;
	  cout << temp_comment -> likes << " likes" << endl;
	  temp_comment = temp_comment -> next_reply;
	}
	temp_post = temp_post -> next_post;
  }
  return true;
}

int feed::like_post(char * title) {
  if (!head) return 1;
  
  post_node * post = locatePost(title, head);
  if (post) {
	post -> likes += 1;
	return 0;
  }
  
  return 2;
}

int feed::display_by_likes(int likes, post_node *& post) {
  return likes;
}

bool feed::create_comment(char * title, char * name, char * text, post_node *& post) {
  return false;
}

bool feed::like_comment(char * title, post_node *& post) {
  return false;
}

int feed::display_comments(char * title) {
  if (!head) return 1;

  /*
  post_node * temp_post = head;
  post_node * post = nullptr;
  
  while (!post && temp_post) {
	if (strcmp(temp_post -> title, title) == 0) post = temp_post;
	temp_post = temp_post -> next_post;
  }
  */

  post_node * post = locatePost(title, head);
  
  if (!post) return 2;
  if (!post -> comment_head) return 3;
  
  comment_node * temp_comment = post -> comment_head;
  cout << endl << "Comments:" <<endl;
  while (temp_comment) {
	  cout << endl << temp_comment -> name << " says:" <<endl;
	  cout << temp_comment -> text << endl;
	  cout << temp_comment -> likes << " likes" << endl;
	  temp_comment = temp_comment -> next_reply;
  }
  return 0;
  
}

bool feed::remove_post(char * title, post_node *& post) {
  return false;
}
