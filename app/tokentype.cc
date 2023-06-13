#include "tokentype.h"

enum class loxx::TokenType {
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
