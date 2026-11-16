#include<stdio.h>
#include<stdint.h>



constexpr size_t CAPACITY = 8;

typedef struct {
  intptr_t head;
  intptr_t tail;
  char array [CAPACITY];
} queue_t;

int enqueue(queue_t *queue, char val) {
  if((queue->tail + 1) % CAPACITY != queue->head) {
    queue->array[queue->tail] = val;
    queue->tail = (queue->tail + 1) % CAPACITY;
  } else {
    return -1;
  }
  return 0;
}

char dequeue(queue_t *queue) {
  if(queue->tail != queue->head) {
    char res = queue->array[queue->head];
    queue->head = (queue->head + 1) % CAPACITY;
    return res;
  } else {
    return 0;
  }
}

int main () {
  queue_t qu = {.tail = 0, .head = 0};

  for(int i = 0; i < 10; ++i) {
    if(enqueue(&qu, (char)(i + 48) ) == 0) {
      continue;
    } else {
      printf("%c\n", dequeue(&qu));
    }
  }
  return 0;
}
