#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"

int main () {
  int rc = fork();

  if (rc == 0) {
    close(STDOUT_FILENO);
    printf("Write to stdout\n");
  }
  else {
    wait(NULL);
    printf("Goodbye from parent\n");
  }
}
