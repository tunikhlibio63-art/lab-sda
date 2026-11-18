#include<stdint.h>
#include<stddef.h>
#include"queue.h"



struct queue_s {
  size_t head;
  size_t tail;
  size_t size;
  char *buf;
};

