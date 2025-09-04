#ifndef TOKENIZE_H
#define TOKENIZE_H

typedef enum TokenTypeEnum {
  SENTINEL = -1,
  WORD,
  PIPE,
  REDIR,
} TokenType;

typedef struct TokenStruct {
  TokenType type;
  char *value;
} Token;

Token *tokenize(char *line);

void free_tokens(Token *token);

#endif
