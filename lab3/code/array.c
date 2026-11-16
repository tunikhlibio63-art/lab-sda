#include<stdio.h>
#include<stdint.h>



constexpr size_t CAPACITY = 8;

typedef struct {
  intptr_t head;
  intptr_t tail;
  char array [CAPACITY];
} queue_t;

int enqueue(queue_t *queue, char val) {
  if(queue->head - queue->tail < CAPACITY) {
    queue->array[queue->head] = val;
    ++queue->head <= CAPACITY ? queue->head : queue->head - CAPACITY;
  } else {
    return -1;
  }
  return 0;
}


int main () {
  queue_t qu = {.tail = 0, .head = 0};

  if(enqueue(&qu, 'a') == 0) {
    return 0;
  } else {
    return -1;
  }
}
