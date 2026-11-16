#include<stdio.h>
#include"queue.h"



int main () {
  queue_t *qu;
  char dest;

  create_queue(&qu);
  printf(" br   | i |val|\n");
  for(int i = 0; i < 10; ++i) {
    if(enqueue(qu, (char)(i + 48)) == 0) {
      peek_front(qu, &dest);
      printf(" main | %d | %c\n", i, dest);
      continue;
    } else {
      dequeue(qu, &dest);
      printf(" else | %d | %c\n", i, dest);
    }
  }
  delete_queue(&qu);
  return 0;
}
