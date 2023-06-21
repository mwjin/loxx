#ifndef TOKEN_TYPE_H_
#define TOKEN_TYPE_H_

#include <ostream>
#include <string>

namespace loxx {
enum class TokenType;
const std::string TokenTypeToStr(const TokenType type);
std::ostream& operator<<(std::ostream& os, const TokenType type);
}  // namespace loxx

#endif
