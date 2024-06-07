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
    case '!':
      AddToken(Match('=') ? TokenType::kBangEqual : TokenType::kBang);
      break;
    case '=':
      AddToken(Match('=') ? TokenType::kEqualEqual : TokenType::kEqual);
      break;
    case '<':
      AddToken(Match('=') ? TokenType::kLessEqual : TokenType::kLess);
      break;
    case '>':
      AddToken(Match('=') ? TokenType::kGreaterEqual : TokenType::kGreater);
      break;
    case '/':
      if (Match('/')) {
        // A comment goes until the end of the line.
        while (Peek() != '\n' && !IsAtEnd()) Advance();
      } else {
        AddToken(TokenType::kSlash);
      }
      break;
    case ' ':
    case '\r':
    case '\t':
      // Ignore whitespace
      break;
    case '\n':
      ++line_;
      break;
    case '"':
      ScanString();
      break;
    default:
      if (IsDigit(c))
        ScanNumber();
      else
        loxx::Error(line_, "Unexpected character.");
      break;
  }
}

void Scanner::ScanString() {
  while (!IsAtEnd() && Peek() != '"') {
    if (Peek() == '\n') ++line_;
    Advance();
  }

  if (IsAtEnd()) {
    loxx::Error(line_, "Unterminated string.");
    return;
  }

  // The closing "
  Advance();

  // Get the unquoted string literal
  AddToken(TokenType::kString);
}

void Scanner::ScanNumber() {
  while (IsDigit(Peek())) Advance();
  if (Peek() == '.' && IsDigit(PeekNext())) {
    Advance();  // Consume the dot
    while (IsDigit(Peek())) Advance();
  }
  AddToken(TokenType::kNumber);
}

void Scanner::AddToken(TokenType token_type) {
  tokens_.emplace_back(token_type, source_.substr(start_, current_ - start_),
                       line_);
}

void Scanner::AddEof() { tokens_.emplace_back(TokenType::kEof, "", line_); }

char Scanner::Advance() { return source_.at(current_++); }

bool Scanner::IsAtEnd() { return current_ >= source_.size(); }

bool Scanner::Match(char c) {
  if (IsAtEnd()) return false;
  if (c != source_.at(current_)) return false;
  current_++;
  return true;
}

char Scanner::Peek() { return IsAtEnd() ? '\0' : source_.at(current_); }

char Scanner::PeekNext() {
  return current_ + 1 >= source_.size() ? '\0' : source_.at(current_ + 1);
}

bool Scanner::IsDigit(char c) { return c >= '0' && c <= '9'; }
}  // namespace loxx
