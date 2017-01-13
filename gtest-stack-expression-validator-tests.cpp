//
// Created by Syed Haris Ali on 1/12/17.
//

#include <Stack/ExpressionValidator.hpp>
#include "gtest/gtest.h"

using namespace ds::stack;

class StackExpressionValidatorTest : public ::testing::Test {

protected:
    ExpressionValidator *mExpressionValidator;

    StackExpressionValidatorTest() {
        mExpressionValidator = new ExpressionValidator();
    }

    ~StackExpressionValidatorTest() {
        delete mExpressionValidator;
    }
};

TEST_F(StackExpressionValidatorTest, BalancedBrackets) {
    ASSERT_TRUE(mExpressionValidator->validate("[]"));
}

TEST_F(StackExpressionValidatorTest, BalancedBraces) {
    ASSERT_TRUE(mExpressionValidator->validate("{}"));
}

TEST_F(StackExpressionValidatorTest, BalancedParens) {
    ASSERT_TRUE(mExpressionValidator->validate("()"));
}

TEST_F(StackExpressionValidatorTest, FullBalanced) {
    ASSERT_TRUE(mExpressionValidator->validate("[{()}]"));
}

TEST_F(StackExpressionValidatorTest, FullBalanced2) {
    ASSERT_TRUE(mExpressionValidator->validate("{[()]}"));
}

TEST_F(StackExpressionValidatorTest, FullBalanced3) {
    ASSERT_TRUE(mExpressionValidator->validate("({[]})"));
}

TEST_F(StackExpressionValidatorTest, FullBalanced4) {
    ASSERT_TRUE(mExpressionValidator->validate("[ chicken sandwich {()}]"));
}

TEST_F(StackExpressionValidatorTest, FullBalanced5) {
    ASSERT_TRUE(mExpressionValidator->validate("{[()] chicken sandwich }"));
}

TEST_F(StackExpressionValidatorTest, FullBalanced6) {
    ASSERT_TRUE(mExpressionValidator->validate("({[ chicken sandwich ]})"));
}

TEST_F(StackExpressionValidatorTest, FullBalanced7) {
    ASSERT_TRUE(mExpressionValidator->validate("({[ chicken ] sandwich })"));
}

TEST_F(StackExpressionValidatorTest, FullBalanced8) {
    ASSERT_TRUE(mExpressionValidator->validate("({ crispy [ chicken ] sandwich })"));
}

TEST_F(StackExpressionValidatorTest, FullBalanced9) {
    ASSERT_TRUE(mExpressionValidator->validate("(spicy { crispy [ chicken ] sandwich })"));
}

TEST_F(StackExpressionValidatorTest, FullBalanced10) {
    ASSERT_TRUE(mExpressionValidator->validate("(spicy { crispy [ chicken ] sandwich } with club sauce)"));
}

TEST_F(StackExpressionValidatorTest, UnbalancedBrackets) {
    ASSERT_FALSE(mExpressionValidator->validate("["));
}

TEST_F(StackExpressionValidatorTest, UnbalancedBraces) {
    ASSERT_FALSE(mExpressionValidator->validate("{"));
}

TEST_F(StackExpressionValidatorTest, UnbalancedParens) {
    ASSERT_FALSE(mExpressionValidator->validate("("));
}

TEST_F(StackExpressionValidatorTest, UnbalancedBrackets2) {
    ASSERT_FALSE(mExpressionValidator->validate("]"));
}

TEST_F(StackExpressionValidatorTest, UnbalancedBraces2) {
    ASSERT_FALSE(mExpressionValidator->validate("}"));
}

TEST_F(StackExpressionValidatorTest, UnbalancedParens2) {
    ASSERT_FALSE(mExpressionValidator->validate(")"));
}

TEST_F(StackExpressionValidatorTest, Unbalanced) {
    ASSERT_FALSE(mExpressionValidator->validate("{)"));
}

TEST_F(StackExpressionValidatorTest, Unbalanced2) {
    ASSERT_FALSE(mExpressionValidator->validate("(}"));
}

TEST_F(StackExpressionValidatorTest, Unbalanced3) {
    ASSERT_FALSE(mExpressionValidator->validate("[ chicken {]"));
}

TEST_F(StackExpressionValidatorTest, Unbalanced4) {
    ASSERT_FALSE(mExpressionValidator->validate("[ } chicken {]"));
}

TEST_F(StackExpressionValidatorTest, Unbalanced5) {
    ASSERT_FALSE(mExpressionValidator->validate(")[ } chicken {]("));
}

TEST_F(StackExpressionValidatorTest, Unbalanced6) {
    ASSERT_FALSE(mExpressionValidator->validate("{[[]}"));
}

TEST_F(StackExpressionValidatorTest, Unbalanced7) {
    ASSERT_FALSE(mExpressionValidator->validate("{][]}"));
}