#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"list_queue_impl.h"



queue_status_t create_queue(queue_t **q, size_t size) {
  *q = malloc(sizeof(queue_t));
  if(*q == nullptr) {
    return QUEUE_ERR_MALLOC;
  }
  (*q)->tail = nullptr;
  (*q)->head = nullptr;
  (*q)->size = size;
  (*q)->capacity = 0;
  return QUEUE_SUCCESS;
}

void delete_queue(queue_t **q) {
  if(q == nullptr || *q == nullptr){
    return;
  }
  node_t *node = (*q)->head;
  while((*q)->head != nullptr) {
    delete_node(*q);
  }
  free(*q);
  *q = nullptr;
}

bool is_empty(queue_t *q) {
  return q->head == nullptr && q->tail == nullptr;
}

bool is_full(queue_t *q) {
  return q->capacity >= q->size;
}

queue_status_t enqueue(queue_t *q, char val) {
  if(is_full(q)) {
    return QUEUE_ERR_FULL;
  }
  queue_status_t status;
  node_t *node = create_node(&status);
  if(status != QUEUE_SUCCESS) {
    return status;
  }
  node->value = val;
  node->next = nullptr;
  if(is_empty(q)) {
    q->head = node;
    q->tail = node;
  }
  q->tail->next = node;
  q->tail = q->tail->next;
  ++q->capacity;
  return status;
}

queue_status_t dequeue(queue_t *q, char *dest) {
  if(is_empty(q)) {
    return QUEUE_ERR_EMPTY;
  }
  *dest = q->head->value;
  delete_node(q);
  --q->capacity;
  return QUEUE_SUCCESS;
}

queue_status_t  peek_front(queue_t *q, char *dest) {
  if(is_empty(q)) {
    return QUEUE_ERR_EMPTY;
  }
  *dest = q->head->value;
  return QUEUE_SUCCESS;
}

