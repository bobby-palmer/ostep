#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
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
