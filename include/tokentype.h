#ifndef TOKEN_TYPE_H_
#define TOKEN_TYPE_H_

#include <ostream>
#include <string>

namespace loxx {
enum class TokenType {
  // Single-character tokens
  kLeftParen,
  kRightParen,
  kLeftBrace,
  kRightBrace,
  kComma,
  kDot,
  kMinus,
  kPlus,
  kSemicolon,
  kSlash,
  kStar,

  // One or two character tokens.
  kBang,
  kBangEqual,
  kEqual,
  kEqualEqual,
  kGreater,
  kGreaterEqual,
  kLess,
  kLessEqual,

  // Literals
  kIdentifier,
  kString,
  kNumber,

  // Keywords
  kAnd,
  kClass,
  kElse,
  kFalse,
  kFun,
  kFor,
  kIf,
  kNil,
  kOr,
  kPrint,
  kReturn,
  kSuper,
  kThis,
  kTrue,
  kVar,
  kWhile,

  kEof
};

const std::string TokenTypeToStr(const TokenType type);
std::ostream& operator<<(std::ostream& os, const TokenType type);
}  // namespace loxx

#endif
