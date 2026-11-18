#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"ring_queue_impl.h"



queue_status_t create_queue(queue_t **q, size_t size) {
  *q = malloc(sizeof(queue_t));
  if(*q == nullptr) {
    return QUEUE_ERR_MALLOC;
  }
  (*q)->buf = malloc(size * sizeof((*q)->buf[0]));
  if((*q)->buf == nullptr) {
    free(*q);
    *q = nullptr;
    return QUEUE_ERR_MALLOC;
  }
  (*q)->size = size;
  (*q)->head = 0;
  (*q)->tail = 0;
  memset((*q)->buf, 0, (*q)->size);
  return QUEUE_SUCCESS;
}

void delete_queue(queue_t **q) {
  if(q == nullptr || *q == nullptr) {
    return;
  }
  if((*q)->buf != nullptr) {
    free((*q)->buf);
    (*q)->buf = nullptr;
  }
  free(*q);
  *q = nullptr;
}

bool is_empty(queue_t *q) {
  return q->tail == q->head;
}

bool is_full(queue_t *q) {
  return (q->tail + 1) % q->size == q->head;
}

queue_status_t enqueue(queue_t *q, char val) {
  if(is_full(q)) {
    return QUEUE_ERR_FULL;
  }
  q->buf[q->tail] = val;
  q->tail = (q->tail + 1) % q->size;
  return QUEUE_SUCCESS;
}

queue_status_t dequeue(queue_t *q, char *dest) {
  if(is_empty(q)) {
    return QUEUE_ERR_EMPTY;
  }
  char res = q->buf[q->head];
  q->head = (q->head + 1) % q->size;
  *dest = res;
  return QUEUE_SUCCESS;
}

queue_status_t peek_front(queue_t *q, char *dest) {
  if(is_empty(q)) {
    return QUEUE_ERR_EMPTY; 
  }
  *dest = q->buf[q->head];
  return QUEUE_SUCCESS;
}
