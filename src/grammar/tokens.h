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
  TOKEN_COLON,

  TOKEN_QUOTE,
  TOKEN_RIGHT_PAREN,
  TOKEN_LEFT_PAREN,
  TOKEN_RIGHT_BRACKET,
  TOKEN_LEFT_BRACKET,

  LITERAL_IDENTIFIER,
  LITERAL_INTEGER,
  LITERAL_DECIMAL,
  LITERAL_STRING,
  LITERAL_BOOLEAN,

  TOKEN_EOF
} token_type_t;

typedef union {
  unsigned char str[1024];
  long long int integer;
  double        decimal;
} TokenValue;

typedef struct {
  token_type_t  type;
  TokenValue    value;
  size_t        indentation;
} Token;

typedef struct {
  Token *items;
  size_t size;
  size_t capacity;
} Tokens;

#endif
