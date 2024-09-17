#include <iostream>
#include <string>
#include <cctype>
#include <gtest/gtest.h>

// Password validation function
bool isValidPassword(const std::string &password) {
    if (password.length() < 8) {
        return false;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (char ch : password) {
        if (std::isupper(ch)) hasUpper = true;
        else if (std::islower(ch)) hasLower = true;
        else if (std::isdigit(ch)) hasDigit = true;
        else if (std::ispunct(ch)) hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Test Case 1: Valid password
TEST(PasswordValidationTest, ValidPassword) {
    std::string password = "Password1!";
    EXPECT_TRUE(isValidPassword(password));
}

// Test Case 2: Less than 8 characters
TEST(PasswordValidationTest, TooShortPassword) {
    std::string password = "P1!";
    EXPECT_FALSE(isValidPassword(password));
}

// Test Case 3: Missing uppercase letter
TEST(PasswordValidationTest, NoUpperCase) {
    std::string password = "password1!";
    EXPECT_FALSE(isValidPassword(password));
}

// Test Case 4: Missing lowercase letter
TEST(PasswordValidationTest, NoLowerCase) {
    std::string password = "PASSWORD1!";
    EXPECT_FALSE(isValidPassword(password));
}





