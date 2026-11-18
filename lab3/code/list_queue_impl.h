#include"queue.h"



typedef struct node_s {
  char value;
  struct node_s *next;
} node_t;

struct queue_s {
  node_t *head;
  node_t *tail;
  size_t size;
  size_t capacity;
};

static inline node_t *create_node(queue_status_t *status) {
  node_t *node = malloc(sizeof(node_t));
  if(node == nullptr) {
    *status = QUEUE_ERR_MALLOC; 
  }
  *status = QUEUE_SUCCESS;
  return node;
}

static inline void delete_node(queue_t *q) { 
  node_t *node = q->head->next;
  free(q->head);
  q->head = node;
}

