#pragma once
#include<stddef.h>

typedef enum : int {
  QUEUE_SUCCESS = 0,
  QUEUE_ERR_NULL,
  QUEUE_ERR_EMPTY,
  QUEUE_ERR_FULL,
  QUEUE_ERR_MALLOC
} queue_status_t;

typedef struct queue_s queue_t;

queue_status_t create_queue(queue_t **q, size_t size);

void delete_queue(queue_t **q);

bool is_empty(queue_t *q);

bool is_full(queue_t *q);

queue_status_t enqueue(queue_t *q, char val);

queue_status_t dequeue(queue_t *q, char *dest);

queue_status_t  peek_front(queue_t *q, char *dest);

double percentage(queue_t *q);

