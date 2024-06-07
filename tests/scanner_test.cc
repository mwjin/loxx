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

TEST(ScannerTest, TokenizeWithNewline) {
  std::string source{
      R"(// Here is my comment
        !! != !+)"};
  Scanner scanner{source};
  auto& result = scanner.ScanTokens();
  std::vector<Token> expected{
      {TokenType::kBang, "!", 2},       {TokenType::kBang, "!", 2},
      {TokenType::kBangEqual, "!=", 2}, {TokenType::kBang, "!", 2},
      {TokenType::kPlus, "+", 2},       {TokenType::kEof, "", 2},
  };
  EXPECT_EQ(result, expected);
}

TEST(ScannerTest, TokenizeWithNewlineAndWhitespaces) {
  std::string source{
      R"(// Here is a comment
    < > = // inline comment
    ( ))"};
  Scanner scanner{source};
  auto& result = scanner.ScanTokens();
  std::vector<Token> expected{
      {TokenType::kLess, "<", 2},       {TokenType::kGreater, ">", 2},
      {TokenType::kEqual, "=", 2},      {TokenType::kLeftParen, "(", 3},
      {TokenType::kRightParen, ")", 3}, {TokenType::kEof, "", 3}};
  EXPECT_EQ(result, expected);
}

TEST(ScannerTest, TokenizeStringLiterals) {
  std::string source{
      R"("Here is my string."
    // Here is my comment
    "This is a multiple
line!")"};
  Scanner scanner{source};
  auto& result = scanner.ScanTokens();
  std::vector<Token> expected{
      {TokenType::kString, "\"Here is my string.\"", 1},
      {TokenType::kString, "\"This is a multiple\nline!\"", 4},
      {TokenType::kEof, "", 4}};
  EXPECT_EQ(result, expected);
}

TEST(ScannerTest, TokenizeNumberLiterals) {
  std::string source{"12.34.56.78.910"};
  Scanner scanner{source};
  auto& result = scanner.ScanTokens();
  std::vector<Token> expected{
      {TokenType::kNumber, "12.34", 1}, {TokenType::kDot, ".", 1},
      {TokenType::kNumber, "56.78", 1}, {TokenType::kDot, ".", 1},
      {TokenType::kNumber, "910", 1},   {TokenType::kEof, "", 1}};
  EXPECT_EQ(result, expected);
}

TEST(ScannerTest, TokenizeIdentifiersAndKeywords) {
  std::string source{R"(// This is a comment.
var a = 1;
if (a == 1) a = 2;
)"};
  Scanner scanner{source};
  auto& result = scanner.ScanTokens();
  std::vector<Token> expected{
      {TokenType::kVar, "var", 2},       {TokenType::kIdentifier, "a", 2},
      {TokenType::kEqual, "=", 2},       {TokenType::kNumber, "1", 2},
      {TokenType::kSemicolon, ";", 2},   {TokenType::kIf, "if", 3},
      {TokenType::kLeftParen, "(", 3},   {TokenType::kIdentifier, "a", 3},
      {TokenType::kEqualEqual, "==", 3}, {TokenType::kNumber, "1", 3},
      {TokenType::kRightParen, ")", 3},  {TokenType::kIdentifier, "a", 3},
      {TokenType::kEqual, "=", 3},       {TokenType::kNumber, "2", 3},
      {TokenType::kSemicolon, ";", 3},   {TokenType::kEof, "", 4}};
  EXPECT_EQ(result, expected);
}
}  // namespace
}  // namespace loxx
