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

bool feed::create_post(char * title, char * text, char * name, char * source) {
  return(title, text, name, source, head);
}

bool feed::create_post(char * title, char * text, char * name, char * source, post_node * post) {
  if (!post) {
	post = new post_node();
	post -> title = title;
	post -> text = text;
	post -> name = name;
	post -> source = source;
	return true;
  }
  else return(title, text, name, source, post -> next_post);
  return false;
}

bool feed::display_all(post_node * post) {
  return false;
}

bool feed::like_post(char * title, post_node * post) {
  return false;
}

int feed::display_by_likes(int likes, post_node * post) {
  return likes;
}

bool feed::create_comment(char * title, char * name, char * text, post_node * post) {
  return false;
}

bool feed::like_comment(char * title, post_node * post) {
  return false;
}

bool feed::display_comments(char * title, post_node * post) {
  return false;
}

bool feed::remove_post(char * title, post_node * post) {
  return false;
}
