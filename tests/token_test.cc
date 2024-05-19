#include "token.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace loxx {
namespace {
TEST(TokenTest, TokenToString) {
  Token identifier{TokenType::kIdentifier, "x1", 10};
  EXPECT_EQ(identifier.ToString(), "Identifier x1 10");

  Token plus{TokenType::kPlus, "+", 10};
  EXPECT_EQ(plus.ToString(), "Plus + 10");
}
}  // namespace
}  // namespace loxx
