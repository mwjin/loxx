#include "token.h"

#include <sstream>

namespace loxx {
Token::Token(const TokenType type, const std::string& lexeme, const int line)
    : type_{type}, lexeme_{lexeme}, line_{line} {}
std::string Token::ToString() const {
  std::ostringstream oss;
  oss << "[ Type: " << type_ << ", Lexeme: \"" << lexeme_
      << "\", Line: " << line_ << " ]";
  return oss.str();
}
bool operator==(const Token& lhs, const Token& rhs) {
  return lhs.type() == rhs.type() && lhs.lexeme() == rhs.lexeme() &&
         lhs.line() == rhs.line();
}

std::ostream& operator<<(std::ostream& os, const Token& rhs) {
  os << rhs.ToString();
  return os;
}
}  // namespace loxx
