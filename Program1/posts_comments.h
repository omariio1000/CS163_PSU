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
  char * name;
  char * text;
  int likes;
};

struct post_node {
  char * title;
  char * text;
  char * name;
  char * source;
  int likes;
  comment_node * comment;
};

class feed {
 public:

  
 private:
  
};
