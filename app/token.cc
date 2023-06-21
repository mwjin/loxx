#include "token.h"

#include <sstream>

namespace loxx {
Token::Token(const TokenType type, const std::string& lexeme, const int line)
    : type_{type}, lexeme_{lexeme}, line_{line} {}
std::string Token::ToString() const {
  std::ostringstream oss;
  oss << type_ << " " << lexeme_ << " " << line_;
  return oss.str();
}
}  // namespace loxx
