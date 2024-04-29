#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
:edit 4.c

:w
:q
:q
:q
#include <string.h>

int main () {
  int rc = fork();
  if (rc < 0) {
    printf("Failed to fork\n");
    exit(1);
  }
  else if (rc == 0) {
    printf("Hello\n");
  }
  else {
    wait(NULL);
    printf("Goodbye\n");
  }
}
