#include<stdio.h>
#include"queue.h"



constexpr size_t CAPACITY = 2;

int main () {
  queue_t *qu = nullptr;
  create_queue(&qu, CAPACITY);
  delete_queue(&qu);
  return 0;
}
