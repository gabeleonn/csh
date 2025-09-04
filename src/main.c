#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "read.h"
#include "shell.h"
#include "lexer.h"

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
    Token *tokens = tokenize(line);
    for (size_t i = 0; tokens[i].type != SENTINEL; i++) {
        printf("type=%d value=%s\n", tokens[i].type, tokens[i].value ? tokens[i].value : "(null)");
    }
    free(line);
    free_tokens(tokens);

    // exec/builtins

    // free builtins
  } while(running);

  return 0;
}
