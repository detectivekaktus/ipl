#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "macros/array.h"
#include "lexer.h"

void usage(const char *name)
{
  printf("Usage: %s < compile > file.ipl\n", name);
  printf("  compile : compiles the source code to x86-64 ELF object file.\n");
}

int main(int argc, char **argv)
{
  if (argc == 1) {
    printf("ERROR: No command specified.\n");
    usage(argv[0]);
    return 1;
  }
  Files files = {0};
  bool compile = false;
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "compile") == 0) {
      compile = true;
      continue;
    }
    else da_append(&files, argv[i]);
  }
  if (!compile) {
    printf("No operation specified for files:\n");
    for (size_t i = 0; i < files.size; i++)
      printf("  %s\n", files.items[i]);
    return 1;
  }

  Lexer lexer = {0};
  Tokens *tokens = lex_file(&lexer, files.items[0]);
  for (size_t i = 0; i < tokens->size; i++)
    printf("  %s\n", tokens->items[i].value);
  da_heapfree(tokens);
  da_free(&files);
  return 0;
}
