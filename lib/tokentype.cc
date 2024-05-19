#include "tokentype.h"

std::ostream& loxx::operator<<(std::ostream& os, const TokenType type) {
  os << TokenTypeToStr(type);
  return os;
}
const std::string loxx::TokenTypeToStr(const TokenType type) {
  switch (type) {
    case TokenType::kLeftParen:
      return "LeftParen";
    case TokenType::kRightParen:
      return "RightParen";
    case TokenType::kLeftBrace:
      return "LeftBrace";
    case TokenType::kRightBrace:
      return "RightBrace";
    case TokenType::kComma:
      return "Comma";
    case TokenType::kDot:
      return "Dot";
    case TokenType::kMinus:
      return "Minus";
    case TokenType::kPlus:
      return "Plus";
    case TokenType::kSemicolon:
      return "Semicolon";
    case TokenType::kSlash:
      return "Slash";
    case TokenType::kStar:
      return "Star";

    // One or two character tokens.
    case TokenType::kBang:
      return "Bang";
    case TokenType::kBangEqual:
      return "BangEqual";
    case TokenType::kEqual:
      return "Equal";
    case TokenType::kEqualEqual:
      return "EqualEqual";
    case TokenType::kGreater:
      return "Greater";
    case TokenType::kGreaterEqual:
      return "GreaterEqual";
    case TokenType::kLess:
      return "Less";
    case TokenType::kLessEqual:
      return "LessEqual";

    // Literals
    case TokenType::kIdentifier:
      return "Identifier";
    case TokenType::kString:
      return "String";
    case TokenType::kNumber:
      return "Number";

    // case TokenType::keywords
    case TokenType::kAnd:
      return "And";
    case TokenType::kClass:
      return "Class";
    case TokenType::kElse:
      return "Else";
    case TokenType::kFalse:
      return "False";
    case TokenType::kFun:
      return "Fun";
    case TokenType::kFor:
      return "For";
    case TokenType::kIf:
      return "If";
    case TokenType::kNil:
      return "Nil";
    case TokenType::kOr:
      return "Or";
    case TokenType::kPrint:
      return "Print";
    case TokenType::kReturn:
      return "Return";
    case TokenType::kSuper:
      return "Super";
    case TokenType::kThis:
      return "This";
    case TokenType::kTrue:
      return "True";
    case TokenType::kVar:
      return "Var";
    case TokenType::kWhile:
      return "While";

    case TokenType::kEof:
      return "Eof";

    default:
      return "Invalid";
  }
}
