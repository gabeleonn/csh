#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

char *readline() {
  char *line = NULL;
  size_t cap = 0;

  for (;;) {
    errno = 0;
    ssize_t input = getline(&line, &cap, stdin);

    if (input == -1) {
      if (feof(stdin)) {
        free(line);
        return NULL;
      }

      if (errno == EINTR) {
        clearerr(stdin);
        continue;
      }

      free(line);
      return NULL;
    }

    if (input != -1 && line[input - 1] == '\n') {
      line[input - 1] = '\0';
    }

    return line;
  }
}
