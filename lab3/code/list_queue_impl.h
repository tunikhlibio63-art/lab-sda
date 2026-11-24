#pragma once
#include"queue.h"
#include<stdlib.h>


typedef struct node_s {
  char value;
  struct node_s *next;
} node_t;

struct queue_s {
  node_t *head;
  node_t *tail;
  size_t limit;
  size_t count;
};

static inline node_t *create_node(queue_status_t *status) {
  node_t *node = malloc(sizeof(node_t));
  if(node == nullptr) {
    *status = QUEUE_ERR_MALLOC; 
  } else {
    *status = QUEUE_SUCCESS;
  }
  return node;
}

