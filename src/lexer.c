#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"

static char *dump_range(const char *start, size_t len) {
    char *s = (char *)malloc(len + 1);
    if (!s) return NULL;
    memcpy(s, start, len);
    s[len] = '\0';
    return s;
}

Token *tokenize(char *line) {
  if (!line) return NULL;

  size_t size = 16;
  size_t n = 0;
  Token *tokens = malloc(sizeof(Token) * (size + 1)); // +1 for sentinel
  if (!tokens) return NULL;

  const char *p = line;
  while (*p) {
    while (isspace((unsigned char)*p)) p++;
    if (!*p) break;

    const char *start = p;
    while (*p && !isspace((unsigned char)*p)) {
        p++;
    }
    tokens[n].type = WORD;
    tokens[n].value = dump_range(start, (size_t)(p - start));
    if (!tokens[n].value) { free(tokens); return NULL; }
    n++;
  }

  // Sentinel
  tokens[n].type = SENTINEL;
  tokens[n].value = NULL;

  return tokens;
}

void free_tokens(Token *tokens) {
  if (!tokens) return;

  for (size_t i = 0; tokens[i].type != (TokenType)-1; i++) {
      if (tokens[i].value) free(tokens[i].value);
  }

  free(tokens);
}