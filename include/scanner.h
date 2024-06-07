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
  void ScanToken();
  void ScanString();
  void ScanNumber();
  void AddToken(TokenType token_type);
  void AddEof();

  /**
   * @brief Return the current character and go ahead
   */
  char Advance();

  bool IsAtEnd();

  /**
   * @brief Return whether the current character is matching with the input
   * character and go ahead if the result is true.
   */
  bool Match(char c);

  /**
   * @brief Look ahead and return the current unconsumed character
   */
  char Peek();

  char PeekNext();

  bool IsDigit(char c);

  const std::string& source_;
  std::vector<Token> tokens_;
  int start_;    // The first char of the lexeme being scanned
  int current_;  // The char of the lexeme currently being considered
  int line_;     // What source line `current_` is on
};
}  // namespace loxx

#endif  // SCANNER_H_
