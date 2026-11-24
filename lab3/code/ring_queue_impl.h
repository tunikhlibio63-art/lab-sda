#pragma once
#include"queue.h"
#include<stddef.h>
#include<stdint.h>



struct queue_s {
  size_t head;
  size_t tail;
  size_t size;
  size_t count;
  char *buf;
};

