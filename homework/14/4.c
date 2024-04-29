#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"
#include <string.h>

int main () {
  int rc = fork();
  if (rc < 0) {
    printf("Fail to fork\n");
    exit(1);
  }
  else if (rc == 0) {
    char* args[2];
    args[0] = strdup("/bin/ls");
    args[1] = NULL;
    execvp(args[0], args);
  }
  else {
    wait(NULL);
  }
}
