#include <stdio.h>
#include <stdlib.h>

#include "read.h"
#include "shell.h"

int main(void) {
  bool running = 1;

  do {
    fputs(SHELL_PROMPT, stdout);
    fflush(stdout);

    char *line = readline();

    if (!line) break;

    // tokenize
    fputs(line, stdout);
    fflush(stdout);
    free(line);

    // check execution if builtin or not

    // free builtins
  } while(running);

  return 0;
}
