#ifndef __IPL_TOKENS
#define __IPL_TOKENS

typedef enum {
  TOKEN_PLUS,
  TOKEN_MINUS,
  TOKEN_STAR,
  TOKEN_SLASH,
  TOKEN_MODULO,
  TOKEN_GREATER,
  TOKEN_GREATER_EQUAL,
  TOKEN_SHIFT_RIGHT,
  TOKEN_LESS,
  TOKEN_LESS_EQUAL,
  TOKEN_SHIFT_LEFT,
  TOKEN_NOT,
  TOKEN_NOT_EQUAL,
  TOKEN_BIT_AND,
  TOKEN_AND,
  TOKEN_BIT_OR,
  TOKEN_OR,
  TOKEN_EQUAL,
  TOKEN_EQUAL_EQUAL,
  TOKEN_LEFT_PAREN,
  TOKEN_RIGHT_PAREN,
  TOKEN_LEFT_BRACKET,
  TOKEN_RIGHT_BRACKET,
  TOKEN_LEFT_BRACE,
  TOKEN_RIGHT_BRACE,
  TOKEN_DOT,
  TOKEN_COMMA,
  TOKEN_SEMICOLON,
  TOKEN_COLON,

  LITERAL_IDENTIFIER,
  LITERAL_INTEGER,
  LITERAL_DECIMAL,
  LITERAL_STRING,

  TOKEN_NEW_LINE,
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
