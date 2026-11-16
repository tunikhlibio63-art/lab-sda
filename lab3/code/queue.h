#pragma once
#include<stdint.h>
#include<stdbool.h>


typedef struct queue_s queue_t;

int create_queue(queue_t **q);

void delete_queue(queue_t **q);

bool is_empty(queue_t *q);

bool is_full(queue_t *q);

int enqueue(queue_t *q, char val);

int dequeue(queue_t *q, char *dest);

int peek_front(queue_t *q, char *dest);


