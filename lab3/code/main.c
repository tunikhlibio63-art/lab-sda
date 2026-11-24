#include"queue.h"
#include<stdio.h>



constexpr size_t CAPACITY = 20;

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

int main () {
  queue_status_t status;
  char buf;
  int intbuf;
  bool once = false;
  queue_t *qu = nullptr;

  create_queue(&qu, CAPACITY);

  while((intbuf = getchar()) != EOF) {
    buf = intbuf;
    if(buf == '\n') {
      continue;
    }

    if(80.0 < percentage(qu)) {
      if(once == false) {
        printf("queue is 80%% full\n");
      }
      once = true;
    }

    err_handler(enqueue(qu, buf));
  }

  while(!is_empty(qu)) {
    err_handler(dequeue(qu, &buf));
    printf("%c\n", buf);
  }

  delete_queue(&qu);
  return 0;
}
