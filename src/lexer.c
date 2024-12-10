#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "macros/array.h"

#define COMPOSE_INT_TOKEN(t, v) (Token) { .type=(t), .value.integer=(v) }
#define COMPOSE_DOUBLE_TOKEN(t, v) (Token) { .type=(t), .value.double=(v) }
#define COMPOSE_STRING_TOKEN(t, v) (Token) { .type=(t), .value.string=(v) }

#define ADVANCE(l, i) (l)->column++; i++

char *read_file(const char *filename)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL) return NULL;

  fseek(file, 0, SEEK_END);
  int len = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *ctn = calloc(len + 1, sizeof(char));

  char c;
  int i = 0;
  while ((c = fgetc(file)) != EOF) {
    ctn[i] = c;
    i++;
  }
  ctn[i] = '\0';
  fclose(file);
  return ctn;
}

Tokens *lex_file(Lexer *lexer, char *filename)
{
  lexer->filename = filename;
  lexer->line = 1;
  lexer->column = 1;
  lexer->indentation = 0;
  lexer->errors = 0;

  Tokens *tokens = da_alloc(Tokens);
  char *ctn = read_file(filename);

  size_t i = 0;
  while (i < strlen(ctn)) {
    char c = ctn[i];
    switch (c) {
      case '\t':
      case ' ': {
        if (c == '\t' || lexer->column == lexer->indentation)
          lexer->indentation++;
        ADVANCE(lexer, i);
      } break;

      case '\n': {
        lexer->line++;
        lexer->indentation = 1;
        lexer->column = 1;
        i++;
      } break;

      default: {
        lexer->errors++;
        printf("%zu:%zu - Invalid syntax: `%c` is not recognized as a token.\n", lexer->line, lexer->column, c);
        ADVANCE(lexer, i);
      } break;
    }
  }
  da_append(tokens, COMPOSE_INT_TOKEN(EOF, 0));

  free(ctn);
  return tokens;
}
