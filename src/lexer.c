#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "macros/array.h"

#define COMPOSE_TOKEN(typ, val, ind) (Token) { .type=(typ), .value=(val), .indentation=(ind) }

#define ADVANCE(l, i) (l)->column++; i++
#define PEAK(ctn, i) (ctn)[i + 1]

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
      case ':': {
        da_append(tokens, COMPOSE_TOKEN(TOKEN_COLON, ":", lexer->indentation));
        ADVANCE(lexer, i);
      } break;

      case '=': {
        if (PEAK(ctn, i) == '=') {
          da_append(tokens, COMPOSE_TOKEN(TOKEN_EQUAL_EQUAL, "==", lexer->indentation));
          ADVANCE(lexer, i);
        }
        else da_append(tokens, COMPOSE_TOKEN(TOKEN_EQUAL, "=", lexer->indentation));
        ADVANCE(lexer, i);
      } break;

      case '(': {
        da_append(tokens, COMPOSE_TOKEN(TOKEN_LEFT_PAREN, "(", lexer->indentation));
        ADVANCE(lexer, i);
      } break;

      case ')': {
        da_append(tokens, COMPOSE_TOKEN(TOKEN_RIGHT_PAREN, ")", lexer->indentation));
        ADVANCE(lexer, i);
      } break;

      case '[': {
        da_append(tokens, COMPOSE_TOKEN(TOKEN_LEFT_BRACKET, "[", lexer->indentation));
        ADVANCE(lexer, i);
      } break;

      case ']': {
        da_append(tokens, COMPOSE_TOKEN(TOKEN_RIGHT_BRACKET, "]", lexer->indentation));
        ADVANCE(lexer, i);
      } break;

      case '{': {
        da_append(tokens, COMPOSE_TOKEN(TOKEN_LEFT_BRACE, "{", lexer->indentation));
        ADVANCE(lexer, i);
      } break;

      case '}': {
        da_append(tokens, COMPOSE_TOKEN(TOKEN_RIGHT_BRACE, "}", lexer->indentation));
        ADVANCE(lexer, i);
      } break;

      case '\t':
      case ' ': {
        if ((c == '\t' || c == ' ') && lexer->column - 1 == lexer->indentation)
          lexer->indentation += (c == '\t') ? 2 : 1;
        ADVANCE(lexer, i);
      } break;

      case '\n': {
        printf("Indentation: %zu\n", lexer->indentation);
        lexer->line++;
        lexer->indentation = 0;
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
  da_append(tokens, COMPOSE_TOKEN(TOKEN_EOF, "EOF", 0));

  free(ctn);
  return tokens;
}
