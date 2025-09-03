#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "read.h"
#include "shell.h"

int main(void) {
  bool running = 1;

  do {
    if (isatty(fileno(stdin)) && isatty(fileno(stdout))) {
      fputs(SHELL_PROMPT, stdout);
      fflush(stdout);
    }

    char *line = readline();

    if (!line) {
      if (isatty(fileno(stdin))) putchar('\n');
      break;
    }

    if (line[0] == '\0') {
      free(line);
      continue;
    }

    // tokenize
    fputs(line, stdout); putchar('\n');  // placeholder
    free(line);

    // exec/builtins

    // free builtins
  } while(running);

  return 0;
}
