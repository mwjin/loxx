#ifndef SCANNER_H_
#define SCANNER_H_

#include <string>
#include <vector>

#include "token.h"

namespace loxx {
class Scanner {
 public:
  Scanner(const std::string& source);
  const std::vector<Token>& ScanTokens();

 private:
  bool IsAtEnd();

  const std::string& source_;
  std::vector<Token> tokens_;
  int start_;    // The first char of the lexeme being scanned
  int current_;  // The char of the lexeme currently being considered
  int line_;     // What source line `current_` is on
};
}  // namespace loxx

#endif  // SCANNER_H_
