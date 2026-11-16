#include<stdlib.h>
#include<string.h>
#include<stdint.h>



constexpr size_t CAPACITY = 8;

typedef struct {
  size_t head;
  size_t tail;
  char buf [CAPACITY];
} queue_t;

int create_queue(queue_t **q) {
  *q = malloc(sizeof(queue_t));
  if(q == nullptr) {
    return -4;
  }
  (*q)->head = 0;
  (*q)->tail = 0;
  memset((*q)->buf, 0, CAPACITY);
  return 0;
}

void delete_queue(queue_t **q) {
  free(*q);
  *q = nullptr;
}

bool is_empty(queue_t *q) {
  return q->tail == q->head;
}

bool is_full(queue_t *q) {
  return (q->tail + 1) % CAPACITY == q->head;
}

int enqueue(queue_t *q, char val) {
  if(is_full(q)) {
    return -1;
  }
  q->buf[q->tail] = val;
  q->tail = (q->tail + 1) % CAPACITY;
  return 0;
}

int dequeue(queue_t *q, char *dest) {
  if(is_empty(q)) {
    return -2;
  }
  char res = q->buf[q->head];
  q->head = (q->head + 1) % CAPACITY;
  *dest = res;
  return 0;
}

int peek_front(queue_t *q, char *dest) {
  if(is_empty(q)) {
    return -3; 
  }
  *dest = q->buf[q->head];
  return 0;
}
