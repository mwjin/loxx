#ifndef TOKEN_H_
#define TOKEN_H_

#include <ostream>
#include <string>

#include "tokentype.h"

namespace loxx {
class Token {
 public:
  Token(const TokenType type, const std::string& lexeme, const int line);
  std::string ToString() const;

  const TokenType type() const { return type_; }
  const std::string lexeme() const { return lexeme_; }
  const int line() const { return line_; }

 private:
  // TODO: Consider hiding these details
  const TokenType type_;
  const std::string lexeme_;
  const int line_;
};

bool operator==(const Token& lhs, const Token& rhs);
std::ostream& operator<<(std::ostream& os, const Token& rhs);

}  // namespace loxx

#endif
