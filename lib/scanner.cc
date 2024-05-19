#include "scanner.h"

#include "error.h"

namespace loxx {
Scanner::Scanner(const std::string& source)
    : source_{source}, start_{}, current_{}, line_{1} {}

const std::vector<Token>& Scanner::ScanTokens() {
  while (!IsAtEnd()) {
    start_ = current_;  // Move to the next lexeme
    ScanToken();
  }

  AddEof();
  return tokens_;
}

void Scanner::ScanToken() {
  char c{Advance()};
  switch (c) {
    case '(':
      AddToken(TokenType::kLeftParen);
      break;
    case ')':
      AddToken(TokenType::kRightParen);
      break;
    case '{':
      AddToken(TokenType::kLeftBrace);
      break;
    case '}':
      AddToken(TokenType::kRightBrace);
      break;
    case ',':
      AddToken(TokenType::kComma);
      break;
    case '.':
      AddToken(TokenType::kDot);
      break;
    case '-':
      AddToken(TokenType::kMinus);
      break;
    case '+':
      AddToken(TokenType::kPlus);
      break;
    case ';':
      AddToken(TokenType::kSemicolon);
      break;
    case '*':
      AddToken(TokenType::kStar);
      break;
    default:
      loxx::Error(line_, "Unexpected character.");
      break;
  }
}

void Scanner::AddToken(TokenType token_type) {
  tokens_.emplace_back(token_type, source_.substr(start_, current_ - start_),
                       line_);
}

void Scanner::AddEof() { tokens_.emplace_back(TokenType::kEof, "", line_); }

char Scanner::Advance() { return source_.at(current_++); }

bool Scanner::IsAtEnd() { return current_ >= source_.size(); }
}  // namespace loxx
