#include"list_queue_impl.h"
#include<stdlib.h>
#include<stdint.h>



queue_status_t create_queue(queue_t **q, size_t limit) {
  if(q == nullptr) {
    return QUEUE_ERR_NULL;
  }
  *q = malloc(sizeof(queue_t));
  if(*q == nullptr) {
    return QUEUE_ERR_MALLOC;
  }
  (*q)->tail = nullptr;
  (*q)->head = nullptr;
  (*q)->limit = limit;
  (*q)->count = 0;
  return QUEUE_SUCCESS;
}

void delete_queue(queue_t **q) {
  if(q == nullptr || *q == nullptr){
    return;
  }
  while((*q)->head != nullptr) {
    node_t *node = (*q)->head;
    (*q)->head = node->next;
    free(node);
  }
  (*q)->tail = nullptr;
  free(*q);
  *q = nullptr;
}

bool is_empty(queue_t *q) {
  return q->head == nullptr;
}

bool is_full(queue_t *q) {
  return q->count >= q->limit;
}

queue_status_t enqueue(queue_t *q, char val) {
  if(q == nullptr) {
    return QUEUE_ERR_NULL;
  }
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
  if(q->head == nullptr) {
    q->head = q->tail = node;
  } else {
    q->tail->next = node;
    q->tail = node;
  }
  ++q->count;
  return status;
}

queue_status_t dequeue(queue_t *q, char *dest) {
  if(q == nullptr) {
    return QUEUE_ERR_NULL;
  }
  if(is_empty(q)) {
    return QUEUE_ERR_EMPTY;
  }
  node_t *node = q->head;
  *dest = q->head->value;
  q->head = node->next;
  if(q->head == nullptr) {
    q->tail = nullptr;
  }
  free(node);
  --q->count;
  return QUEUE_SUCCESS;
}

queue_status_t  peek_front(queue_t *q, char *dest) {
  if(q == nullptr) {
    return QUEUE_ERR_NULL;
  }
  if(is_empty(q)) {
    return QUEUE_ERR_EMPTY;
  }
  *dest = q->head->value;
  return QUEUE_SUCCESS;
}

double percentage(queue_t *q) {
  return (100.0 * (double)(q->count) / (double)(q->limit));
}
