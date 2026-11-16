#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>


constexpr size_t CAPACITY = 8;

typedef struct {
  intptr_t head;
  intptr_t tail;
  char array [CAPACITY];
} queue_t;

bool is_empty(queue_t *queue) {
  return queue->tail != queue->head;
}

bool is_full(queue_t *queue) {
  return (queue->tail + 1) % CAPACITY != queue->head;
}

int enqueue(queue_t *queue, char val) {
  if(is_full(queue)) {
    queue->array[queue->tail] = val;
    queue->tail = (queue->tail + 1) % CAPACITY;
  } else {
    return -1;
  }
  return 0;
}

char dequeue(queue_t *queue) {
  if(is_empty(queue)) {
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
