#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int main () {
  int rc = fork();

  if (rc == 0) {
    int p = wait(NULL);
    printf("process = %d, waiting on : %d\n", getpid(), p);
  } 
  else {
    wait(NULL);
    printf("goodbye from process %d\n", getpid());
  }
}
