#include "stdlib.h"
#include "unistd.h"
#include <stdio.h>

int main () {
  int rc = fork();

  if (rc == 0) {
    printf("hello from child %d\n", getpid());
  }
  else {
    int p = waitpid(rc, NULL, 0);
    printf("Goodbye from parent : %d\n", getpid());
  }
}
