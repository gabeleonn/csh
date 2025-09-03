#include <stdlib.h>
#include <stdio.h>

char *readline() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  read = getline(&line, &len, stdin);

  if (read != -1 && line[read - 1] == '\n') {
    line[read - 1] = '\0';
  }

  return line;
}
