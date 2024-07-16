#include "token_type.cpp"

class Token {
 public:
  final TokenType type;
  final std::string lexeme;
  final Object literal;
  final int line;

  Token(TokenType type, std::string lexeme, Object literal, int line)
      : type(type), lexeme(lexeme), literal(literal), line(line) {}

  Token(TokenType type, std::string lexeme, std::shared_ptr<Object> literal,
        int line)
      : type(type), lexeme(lexeme), literal(literal), line(line) {}

 public
  std::string toString() { return type + " " + lexeme + " " + literal; }
};