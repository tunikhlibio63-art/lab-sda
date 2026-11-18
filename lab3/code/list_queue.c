#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"list_queue_impl.h"



queue_status_t create_queue(queue_t **q) {
  *q = malloc(sizeof(queue_t));
  if(*q == nullptr) {
    return QUEUE_ERR_MALLOC;
  }
  (*q)->tail = nullptr;
  (*q)->head = nullptr;
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
  return false;
}

queue_status_t enqueue(queue_t *q, char val) {
  queue_status_t status;
  node_t *node = create_node(&status);
  if(status != QUEUE_SUCCESS) {
    return status;
  }
  node->value = val;
  node->next = nullptr;
  if(is_empty(q)) {
    q->head = node;
  }
  q->tail = node;
  return status;
}

queue_status_t dequeue(queue_t *q, char *dest) {
  *dest = q->head->value;
  delete_node(q);
  return QUEUE_SUCCESS;
}

queue_status_t  peek_front(queue_t *q, char *dest) {
  if(is_empty(q)) {
    return QUEUE_ERR_EMPTY;
  }
  *dest = q->head->value;
  return QUEUE_SUCCESS;
}

