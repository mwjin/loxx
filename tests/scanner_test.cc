#include "scanner.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "token.h"

namespace loxx {
namespace {
TEST(ScannerTest, TokenizeSingleChars) {
  std::string source{"*+-."};
  Scanner scanner{source};
  auto& result = scanner.ScanTokens();
  std::vector<Token> expected{
      {TokenType::kStar, "*", 1},  {TokenType::kPlus, "+", 1},
      {TokenType::kMinus, "-", 1}, {TokenType::kDot, ".", 1},
      {TokenType::kEof, "", 1},
  };
  EXPECT_EQ(result, expected);
}

TEST(ScannerTest, TokenizeStartsWithBang) {
  std::string source{"!!!=!+"};
  Scanner scanner{source};
  auto& result = scanner.ScanTokens();
  std::vector<Token> expected{
      {TokenType::kBang, "!", 1},       {TokenType::kBang, "!", 1},
      {TokenType::kBangEqual, "!=", 1}, {TokenType::kBang, "!", 1},
      {TokenType::kPlus, "+", 1},       {TokenType::kEof, "", 1},
  };
  EXPECT_EQ(result, expected);
}

TEST(ScannerTest, TokenizeComments) {
  std::string source{"// !!!+++"};
  Scanner scanner{source};
  auto& result = scanner.ScanTokens();
  std::vector<Token> expected{{TokenType::kEof, "", 1}};
  EXPECT_EQ(result, expected);
}

TEST(ScannerTest, TokenizeSlash) {
  std::string source{"/!!++"};
  Scanner scanner{source};
  auto& result = scanner.ScanTokens();
  std::vector<Token> expected{
      {TokenType::kSlash, "/", 1}, {TokenType::kBang, "!", 1},
      {TokenType::kBang, "!", 1},  {TokenType::kPlus, "+", 1},
      {TokenType::kPlus, "+", 1},  {TokenType::kEof, "", 1}};
  EXPECT_EQ(result, expected);
}
}  // namespace
}  // namespace loxx
