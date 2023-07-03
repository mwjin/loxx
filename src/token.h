#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

#include "tokentype.h"

namespace loxx {
class Token {
  Token(const TokenType type, const std::string& lexeme, const int line);
  std::string ToString() const;

 private:
  // TODO: Consider hiding these details
  const TokenType type_;
  const std::string lexeme_;
  const int line_;
};
}  // namespace loxx

#endif
