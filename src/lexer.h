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
  size_t errors;
} Lexer;

#endif
