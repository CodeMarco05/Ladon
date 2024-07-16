#include <string>
#include <vector>

#include "token.cpp"
#include "token_type.cpp"

class Scanner {
 public:
  Scanner(const std::string source) : source(source) {}

  std::vector<Token> scanTokens() {
    while (!isAtEnd()) {
      // We are at the beginning of the next lexeme.
      start = current;
      scanToken();
    }

    tokens.push_back(Token(TokenType::ENDOFFILE, "", nullptr, line));
    return tokens;
  }

  



 private:
  const std::string source;
  const std::vector<Token> tokens;
  int start = 0;
  int current = 0;
  int line = 1;
};