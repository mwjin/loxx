#include "scanner.h"

#include "error.h"

namespace loxx {
Scanner::Scanner(const std::string& source)
    : source_{source}, start_{}, current_{}, line_{1} {}

const auto Scanner::keywords_ = std::unordered_map<std::string, TokenType>{
    {"and", TokenType::kAnd},       {"class", TokenType::kClass},
    {"else", TokenType::kElse},     {"false", TokenType::kFalse},
    {"for", TokenType::kFor},       {"fun", TokenType::kFun},
    {"if", TokenType::kIf},         {"nil", TokenType::kNil},
    {"or", TokenType::kOr},         {"print", TokenType::kPrint},
    {"return", TokenType::kReturn}, {"super", TokenType::kSuper},
    {"this", TokenType::kThis},     {"true", TokenType::kTrue},
    {"var", TokenType::kVar},       {"while", TokenType::kWhile},
};

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

      else if (IsAlpha(c))
        ScanIdentifier();
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

void Scanner::ScanIdentifier() {
  while (IsAlphaNumeric(Peek())) Advance();
  auto word = source_.substr(start_, current_ - start_);
  if (keywords_.find(word) != keywords_.end())
    AddToken(keywords_.at(word));
  else
    AddToken(TokenType::kIdentifier);
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
bool Scanner::IsAlpha(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}
bool Scanner::IsAlphaNumeric(char c) { return IsDigit(c) || IsAlpha(c); }
}  // namespace loxx
