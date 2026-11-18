#include<stdio.h>
#include"queue.h"



constexpr size_t CAPACITY = 128;

int main () {
  queue_t *qu = nullptr;
  char dest = 0;

  create_queue(&qu, CAPACITY);
  enqueue(qu, dest++);
  enqueue(qu, dest++);
  enqueue(qu, dest++);
  dequeue(qu, &dest);
  printf("%d\n", dest);
  dequeue(qu, &dest);
  printf("%d\n", dest);
  delete_queue(&qu);
  delete_queue(&qu);
  return 0;
}
