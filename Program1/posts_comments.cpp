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

feed::feed() {
  head = nullptr;
}

feed::~feed() {
  delete head;
  head = nullptr;
}

bool feed::create_post(char * inTitle, char * inText, char * inName, char * inSource) {
  return(inTitle, inText, inName, inSource, head);
}

bool feed::create_post(char * inTitle, char * inText, char * inName, char * inSource, post_node *& post) {
  if (!post) {
	post = new post_node();
	post -> title = inTitle;
	post -> text = inText;
	post -> name = inName;
	post -> source = inSource;
	return true;
  }
  else return(title, text, name, source, post -> next_post);
  return false;
}

bool feed::display_all() {
  return false;
}

bool feed::like_post(char * title, post_node *& post) {
  return false;
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

bool feed::display_comments(char * title, post_node *& post) {
  return false;
}

bool feed::remove_post(char * title, post_node *& post) {
  return false;
}
