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
  int likes = 0; //comment like count
  comment_node * next_reply; //reply to comment
};

struct post_node {
  char * title; //title of post
  char * text; //contents of post
  char * name; //name of poster
  char * source; //original poster (if reposted)
  int likes = 0; //like count
  comment_node * comment_head; //first comment under post
  post_node * next_post; //next post in feed
};

class feed {//ADT class for social media feed
  
public:
  feed(); //constructor
  ~feed(); //destructor

  //wrapper for post creation function
  int create_post(char * title, char * text, char * name, char * source);
  //function for displaying entire feed
  int display_all();
  //function to like post
  int like_post(char * title);
  //function to display based on like count
  int display_by_likes(int likes);
  //wrapper for commenting
  int create_comment(char * title, char * name, char * text);
  //funciton to like comment
  int like_comment (char * titile, char * name);
  //function to display comments on one post
  int display_comments(char * title);
  //wrapper function for removing post
  int remove_post(char * title); 
  
private:
  post_node * head = nullptr; //head pointer for first post
  //recursive function for post creation
  int create_post(post_node * inPost, post_node *& post);
  //recursive function for commenting
  int create_comment(comment_node * inComment, comment_node *& comment);
  //recursive function to remove posts
  int remove_post(post_node *& deleting, post_node *& post);
};
