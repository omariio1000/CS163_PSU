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

    //deleting every post and comment in list
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

    //pointing back to null at the end
    head = nullptr;
}

//function locates a post and returns it
post_node* locatePost(char * inTitle, post_node * post) {
    if (!post) return nullptr; //nothing found
    if (strcmp(inTitle, post -> title) == 0) return post;
    else return locatePost(inTitle, post -> next_post);
}

//function that locates a comment and returns it
comment_node* locateComment(char * inName, comment_node * comment) {
    if (!comment) return nullptr; //nothing found
    if (strcmp(inName, comment -> name) == 0) return comment;
    else return locateComment(inName, comment -> next_reply);
}

//wrapper function for post creation
int feed::create_post(char * inTitle, char * inText, char * inName, char * inSource) {
    //if input is invalid
    if (!inTitle || !inText || !inName) return 7;

    //making a new node to pass into recursive function
    post_node * new_post = new post_node;
    new_post -> title = inTitle;
    new_post -> text = inText;
    new_post -> name = inName;
    new_post -> source = inSource;
    return create_post(new_post, head);
}

//recursive function for post creation
int feed::create_post(post_node * inPost, post_node *& post) {
    if (!post) {//when found the end of the list
        post = inPost;
        return 0;
    }

    int length = strlen(inPost -> title);
    bool inLarger = false; 

    //sorting in alphabetical order
    for (int i = 0; i < length + 1; i++) {
        //if they're identical to this point but one is longer, the the shortest is first
        if (i == length + 1) inLarger = true;
        else if (!post -> title[i]) i = length;
        //if the one coming in should be first
        else if (tolower(inPost -> title[i]) < tolower(post -> title[i])) {
            inLarger = true;
            i = length;
        }
        //if the one coming in should be after this one
        else if (tolower(inPost -> title[i]) > tolower(post -> title[i]))
                i = length;
    }
    
    //if the post comes next in alphabetical order
    if (inLarger) {
        post_node * temp = post;
        post = inPost;
        inPost -> next_post = temp;
        return 0;
    }

    return create_post(inPost, post -> next_post);
}

//function to display all posts and comments
int feed::display_all() {  
    if (!head) return 3; //if list is empty

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

        cout << endl << "------------------------------" << endl;
    }
    return -1; //successfully displayed entire list
}

//function to like post
int feed::like_post(char * title) {
    if (!head) return 3; //if feed is empty

    post_node * post = locatePost(title, head);
    if (post) {
        post -> likes += 1;
        return 8; //successfully liked
    }

    return 4; //couldn't find post
}

//function to display posts with certain like count
int feed::display_by_likes(int inLikes) {
    if (!head) return 3; //feed is empty

    //int to store whether or not any posts were found with like count
    int foundAny = 6;

    post_node * temp_post = head;
    while (temp_post) {
        if (temp_post -> likes >= inLikes) {
            foundAny = -1; //found at least one post
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
        }
        temp_post = temp_post -> next_post;

        cout << endl << "------------------------------" << endl;

    }

    return foundAny;
}

//wrapper function for commenting
int feed::create_comment(char * inTitle, char * inName, char * inText) {
    if (!head) return 3; //feed is empty
    if (!inTitle || !inName || !inText) return 7; //input invalid
    post_node * post = locatePost(inTitle, head);
    if (!post) return 4; //post not found

    //making a new comment for recursive function
    comment_node * comment = new comment_node;
    comment -> name = inName;
    comment -> text = inText;

    return create_comment(comment, post -> comment_head);

}

//recursive function for commenting
int feed::create_comment(comment_node * inComment, comment_node *& comment) {
    if (!comment) {
        comment = inComment;
        return 1; //comment successfully created
    }
    return create_comment(inComment, comment -> next_reply);
}

//function to like a comment
int feed::like_comment(char * title, char * name) {
    if (!head) return 3; //feed is empty

    post_node * post = locatePost(title, head);
    if (!post) return 4; //post not found

    comment_node * comment = locateComment(name, post -> comment_head);
    if (!comment) return 5; //comment not found

    comment -> likes += 1;
    return 9; //liked successfully
}

//function to display all comments on one post
int feed::display_comments(char * title) {
    if (!head) return 3; //feed empty

    post_node * post = locatePost(title, head);

    if (!post) return 4; //post not found

    cout << endl << post -> title << endl;
    cout << "Posted by " << post -> name << endl;
    if (post -> source) cout << "Reposted from " << post -> source << endl;
    cout << endl << post -> text << endl;
    cout << post -> likes << " likes" << endl;

    if (!post -> comment_head) return 11; //no comments on post

    comment_node * temp_comment = post -> comment_head;
    cout << endl << "Comments:" <<endl;
    while (temp_comment) {
        cout << endl << temp_comment -> name << " says:" <<endl;
        cout << temp_comment -> text << endl;
        cout << temp_comment -> likes << " likes" << endl;
        temp_comment = temp_comment -> next_reply;
    }
    return -1; //successfully displayed

}

//wrapper function for removing posts
int feed::remove_post(char * title) {
    if (!head) return 3; //empty feed, nothing to delete
    post_node * deleting = locatePost(title, head);
    if (!deleting) return 4; //no post found    

    //if deleting head no need for recursive
    if (deleting == head) {
        post_node * temp = head -> next_post;
        delete head;
        head = temp;
        return 2; //deleted successfully
    }

    else return remove_post(deleting, head);
}

//recursive function for removing posts
int feed::remove_post(post_node *& deleting, post_node *& current) {

    //unknown error, current should never be null when passed in here
    if (!current) return 10;

    if (current -> next_post == deleting) {
        current -> next_post = deleting -> next_post;
        delete deleting;
        deleting = nullptr;
        return 2; //deleted successfully
    }
    return remove_post(deleting, current -> next_post);
}
