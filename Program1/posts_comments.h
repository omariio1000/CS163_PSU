/*Omar Nassar
 *Portland State University CS163
 *October 1, 2021
 *ADT for social media posts with comments (linked list within a linked list)
 */

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

struct comment_node {
  char * name; //name of comment poster
  char * text; //contents of comment
  int likes; //comment like count
  comment_node * next_reply; //reply to comment
};

struct post_node {
  char * title; //title of post
  char * text; //contents of post
  char * name; //name of poster
  char * source; //original poster (if reposted)
  int likes; //like count
  comment_node * comment_head; //first comment under post
  post_node * next_post; //next post in feed
};

class feed {//ADT class for social media feed
  
public:
  feed(); //constructor
  ~feed(); //destructor
  bool create_post(char * title, char * text, char * name, char * source); //wrapper for next line
  bool create_post(char * title, char * text, char * name, char * source, post_node *& post); //function for post creation
  bool display_all(); //function to display all posts and comments
  bool like_post(char * title, post_node *& post); //function to like post
  int display_by_likes(int likes, post_node *& post); //function to only display posts with certain like counts and their comments
  bool create_comment(char * title, char * name, char * text, post_node *& post); //function to comment on post
  bool like_comment (char * title, post_node *& post); //function to like comment
  bool display_comments(char * title, post_node *& post); //function to display comments on certain post
  bool remove_post(char * title, post_node *& post); //function to remove post and associated comments based on title
  
private:
  post_node * head; //head pointer for first post
  
};
