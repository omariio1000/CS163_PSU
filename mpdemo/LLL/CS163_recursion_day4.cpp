#include "list.h"

float average_calc(node * head) {
  if (!head) return 0.0;

  int count {0};
  int sum {0};
  count = counts_and_sums(head, sum);

  return float(sum)/count;
}

//Recursion returns count and calculates summ
int counts_and_sums(node * head, int & sum) {
  if (!head) return 0;

  sum += head -> data;
  return 1 + counts_and_sums(head -> next, sum);
}
