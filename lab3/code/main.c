#include"queue.h"
#include<stdio.h>



constexpr size_t CAPACITY = 100;

constexpr char ESC = 27;

void err_handler(queue_status_t status){
  switch (status) {
    case QUEUE_SUCCESS:
      return;
    case QUEUE_ERR_NULL:
      fprintf(stderr, "error: queue is null pointer\n");
      return;
    case QUEUE_ERR_EMPTY:
      fprintf(stderr, "error: queue is empty\n");
      return;
    case QUEUE_ERR_FULL:
      fprintf(stderr, "error: queue is full\ninfo: press CTRL + D to finish\n");
      return;
    case QUEUE_ERR_MALLOC:
      fprintf(stderr, "error: failed to allocate memory\n");
      return;
    default:
      fprintf(stderr, "error: unknown state recived\n");
  }
}

void output_queue(queue_t *q) {
  char buf = 0;
  unsigned long row_len = 20;
  unsigned long counter = 0;
  while(!is_empty(q)) {
    if(counter >= row_len) {
      printf("\n");
      counter = 0;
    }
    err_handler(dequeue(q, &buf));
    printf("%c ", buf);
    ++counter;
  }
  printf("\n");
}

void input_queue(queue_t *q) {
  char buf;
  int intbuf;
  bool once = false;

  while((intbuf = getchar()) != EOF) {
    buf = intbuf;
    if(buf == '\n') {
      continue;
    } 
    if(buf == ESC) {
      return;
    }
    if(80.0 < percentage(q)) {
      if(once == false) {
        fprintf(stderr, "queue is 80%% full\n");
      }
      once = true;
    }

    err_handler(enqueue(q, buf));
  }
}

int main () {
  queue_t *q = nullptr;

  err_handler(create_queue(&q, CAPACITY));
  
  char c;
  err_handler(dequeue(q, &c));

  input_queue(q);

  output_queue(q);

  delete_queue(&q);

  return 0;
}
