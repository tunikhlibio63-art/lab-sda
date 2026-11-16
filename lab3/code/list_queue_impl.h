#include"queue.h"



typedef struct node_s {
  char value;
  struct node_s *next;
} node_t;

struct queue_s {
  node_t *head;
  node_t *tail;
};
