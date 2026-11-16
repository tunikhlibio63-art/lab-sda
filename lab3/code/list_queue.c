#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"list_queue_impl.h"



queue_status_t create_queue(queue_t **q) {
  *q = malloc(sizeof(queue_t));
  if(*q == nullptr) {
    return QUEUE_ERR_MALLOC;
  }
  node_t *node = malloc(sizeof(node_t));
  if(node == nullptr) {
    free(*q);
    *q = nullptr;
    return QUEUE_ERR_MALLOC;
  }
  node->value = 0;
  node->next = node;
  (*q)->tail = node;
  (*q)->head = node;
  return QUEUE_SUCCESS;
}

void delete_queue(queue_t **q) {
  if(q == nullptr || *q == nullptr){
    return;
  }
  node_t *start = (*q)->head;
  node_t *current = (*q)->head;
  node_t *next;
  do {
    next = current->next;
    free(current);
    current = next;
  } while(current != start);
  free(*q);
  *q = nullptr;
}

bool is_empty(queue_t *q) {return 0;}

bool is_full(queue_t *q) {return 0;}

queue_status_t enqueue(queue_t *q, char val) {return 0;}

queue_status_t dequeue(queue_t *q, char *dest) {return 0;}

queue_status_t  peek_front(queue_t *q, char *dest) {return 0;}

