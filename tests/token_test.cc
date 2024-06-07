#include "token.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace loxx {
namespace {
TEST(TokenTest, TokenToString) {
  Token identifier{TokenType::kIdentifier, "x1", 10};
  EXPECT_EQ(identifier.ToString(),
            "[ Type: Identifier, Lexeme: \"x1\", Line: 10 ]");

  Token plus{TokenType::kPlus, "+", 10};
  EXPECT_EQ(plus.ToString(), "[ Type: Plus, Lexeme: \"+\", Line: 10 ]");
}

TEST(TokenTest, TokenEqual) {
  Token plus1{TokenType::kPlus, "+", 1};
  Token plus2{TokenType::kPlus, "+", 2};
  Token minus{TokenType::kMinus, "-", 1};

  EXPECT_EQ(plus1, plus1);
  EXPECT_NE(plus1, plus2);
  EXPECT_NE(plus2, minus);
}
}  // namespace
}  // namespace loxx
