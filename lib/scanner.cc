#include "scanner.h"

namespace loxx {
Scanner::Scanner(const std::string& source)
    : source_{source}, start_{}, current_{}, line_{1} {}

const std::vector<Token>& Scanner::ScanTokens() {
  while (!IsAtEnd()) {
    // TODO: Scan one token for the current lexeme
    start_ = current_;  // Move to the next lexeme
  }
  // TODO: Add the EOF token
  return tokens_;
}

bool Scanner::IsAtEnd() { return current_ >= source_.size(); }
}  // namespace loxx
