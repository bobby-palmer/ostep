#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include <string.h>

int main () {
  int rc = fork();
  int fd[2];
  pipe(fd);
  if (rc == 0) {
    if (fork() == 0) {
      int MAX_LINE = 256;
      char buffer[256];
      read(fd[0], buffer, MAX_LINE);
      printf("Message : %s\n", buffer);
    }
    else {
      char* message = "Hello from other child\n";
      write(fd[1], message, strlen(message));
    }
  }
}
