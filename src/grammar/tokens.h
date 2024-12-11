#ifndef __IPL_TOKENS
#define __IPL_TOKENS

typedef enum {
  TOKEN_SET,
  TOKEN_RET,
  TOKEN_CALL,
  TOKEN_PRINT,
  TOKEN_INTEGER,
  TOKEN_DECIMAL,
  TOKEN_STRING,

  TOKEN_EQUAL,
  TOKEN_EQUAL_EQUAL,
  TOKEN_COLON,
  TOKEN_LEFT_PAREN,
  TOKEN_RIGHT_PAREN,
  TOKEN_LEFT_BRACKET,
  TOKEN_RIGHT_BRACKET,
  TOKEN_LEFT_BRACE,
  TOKEN_RIGHT_BRACE,

  LITERAL_IDENTIFIER,
  LITERAL_INTEGER,
  LITERAL_DECIMAL,
  LITERAL_STRING,

  TOKEN_EOF
} token_type_t;

typedef struct {
  token_type_t type;
  char *value;
  size_t indentation;
} Token;

typedef struct {
  Token *items;
  size_t size;
  size_t capacity;
} Tokens;

#endif
