#include"queue.h"
#include<stdio.h>
#include<string.h>



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
      getchar();
      return;
    }
    if(80 <= (int)percentage(q)) {
      if(once == false) {
        fprintf(stderr, "queue is 80%% full\n");
      }
      once = true;
    }
    
    if(80 > (int)percentage(q)) {
      once = true;
    }
    err_handler(enqueue(q, buf));
  }
}

int main () {
  queue_t *q = nullptr;
  char in_buf[64];
  int cc;
  queue_status_t status;
  err_handler(create_queue(&q, CAPACITY));

  for(;;) {
    printf("[cmd]> ");
    fflush(stdout);

    if(fgets(in_buf, sizeof(in_buf), stdin) == nullptr) {
      printf("\n");
      break;
    }

    int too_long = 0;
    char *nl = strchr(in_buf, '\n');

    if(nl != nullptr) {
      *nl = '\0';
    } else {
      int c;
      while((c = getchar()) != '\n' && c != EOF) {
        too_long = 1;
      }
    }
    if(too_long) {
      continue;
    }

    if(strcmp(in_buf, "exit") == 0) {
      break;
    } else if(strcmp(in_buf, "input") == 0) {
      input_queue(q);
    } else if(strcmp(in_buf, "output") == 0) {
      output_queue(q);
    } else if(strcmp(in_buf, "add") == 0) {
      if((cc = getchar()) == EOF) {
        break;
      }
      err_handler(enqueue(q, (char)cc));
      while(getchar() != '\n') {}
    } else if(strcmp(in_buf, "del") == 0) {
        err_handler(status = dequeue(q, (char *)&cc));
        if (status == QUEUE_SUCCESS) {
          printf("%c\n", (char)cc);
    }
    } else if(strcmp(in_buf, "perc") == 0) {
      printf("%2.0f%%\n", percentage(q));
    }
  }

  delete_queue(&q);

  return 0;
}
