#ifndef __IPL_LEXER
#define __IPL_LEXER

#include "grammar/tokens.h"

typedef struct {
  char **items;
  size_t size;
  size_t capacity;
} Files;

typedef struct {
  char  *filename;
  size_t line;
  size_t column;

  size_t indentation;
  size_t errors;
} Lexer;

Tokens *lex_file(Lexer *lexer, char *filename);

#endif
