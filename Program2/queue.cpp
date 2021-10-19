/*Omar Nassar
 * Portland State University CS163
 * October 18, 2021
 * ADT implementation for storing message board using queue
 */

#include "queue.h"

#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>

using namespace std;

queue::queue() { 
    q_head = nullptr;
}

queue::~queue() {
  queue_node * temp;
  do {
      temp = q_head -> next;
      delete q_head;
      q_head = temp;
  } while (q_head);
  
}

int queue::enqueue(stack & inMessages) {
    return 0;
}

int queue::dequeue() {
    return 0;
}

int display_all() {
    return 0;
}
