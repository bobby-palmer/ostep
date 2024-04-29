#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int main() {
  int x = 100;
  int rc = fork();
  if (rc < 0) {
    printf("ERROR FORKING\n");
    exit(1);
  }
  else if (rc == 0) {
    printf("Child initial value of x : %d\n", x);
    x = 101;
    printf("Child final value : %d\n", x);
  }
  else {
    // parent
    printf("Parent initial value of x : %d\n", x);
    x = 99;
    printf("Parent final value of x : %d\n", x);
  }
}
