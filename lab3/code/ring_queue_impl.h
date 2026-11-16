#include<stdint.h>
#include"queue.h"

constexpr size_t CAPACITY = 8;

struct queue_s {
  size_t head;
  size_t tail;
  char buf [CAPACITY];
};

