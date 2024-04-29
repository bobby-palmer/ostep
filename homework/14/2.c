#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"
#include <string.h>

int main () {
  int fd = open("./out.txt", O_WRONLY | O_APPEND | O_CREAT);
  int rc = fork();
  if (rc < 0) {
    printf("ERROR IN FORK");
  }
  else if (rc == 0) {
    //child
    char* buf = "Child writing\n";
    write(fd, buf, strlen(buf));
  }
  else {
    //parent
    char* buf = "Parent writing\n";
    write(fd, buf, strlen(buf));
  }
}
