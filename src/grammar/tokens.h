#ifndef __IPL_TOKENS
#define __IPL_TOKENS

typedef enum {
  TOKEN_SET,
  TOKEN_RET,
  TOKEN_CALL,

  TOKEN_COLON,
  TOKEN_EQUAL,

  TOKEN_NUMBER,
  TOKEN_DECIMAL,
  TOKEN_STRING,
  TOKEN_IDENTIFIER
} token_type_t;

typedef union {
  unsigned char str[1024];
  long long int integer;
  double        decimal;
} TokenValue;

typedef struct {
  token_type_t  type;
  TokenValue    value;
} Token;

typedef struct {
  Token *items;
  size_t size;
  size_t capacity;
} Tokens;

#endif
