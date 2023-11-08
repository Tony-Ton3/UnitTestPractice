/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test {
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, smoke_test) {
    ASSERT_TRUE( 1 == 1 );
}

// TESTS FOR count_leading_characters

TEST(PasswordTest, single_letter_password) {
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, letters_repeated_at_end) {
	Password my_password;
	int actual = my_password.count_leading_characters("Zoo");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, uppercase_lowercase_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("ZZzz");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, number_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("00000001");
	ASSERT_EQ(7, actual);
}

TEST(PasswordTest, empty_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, diff_langauge_letters) {
	Password my_password;
	int actual = my_password.count_leading_characters("оoooooooooo");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, repeating_spaces) {
	Password my_password;
	int actual = my_password.count_leading_characters("     ");
	ASSERT_EQ(5, actual);
}

TEST(PasswordTest, repeating_special_characters) {
	Password my_password;
	int actual = my_password.count_leading_characters("&&&&&");
	ASSERT_EQ(5, actual);
}

// TESTS FOR has_mixed_case

TEST(PasswordTest, empty_case){
	Password my_password;
	bool result = my_password.has_mixed_case("");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, one_letter) {
	Password my_password;
	bool result = my_password.has_mixed_case("A");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, only_lowercase){
	Password my_password;
	bool result = my_password.has_mixed_case("aaaaa");
	ASSERT_NE(true, result);
}

TEST(PasswordTest, only_uppercase){
	Password my_password;
	bool result = my_password.has_mixed_case("AAAA");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, both_upper_lower) {
	Password my_password;
	bool result = my_password.has_mixed_case("Az");
	ASSERT_EQ(true, result);
}

TEST(PasswordTest, special_characters) {
	Password my_password;
	bool result = my_password.has_mixed_case("A&&&");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, upper_lower_special_characters) {
	Password my_password;
	bool result = my_password.has_mixed_case("12\nA&&&zyyyAlllmmm;;\n\0");
	ASSERT_EQ(true, result);
}

TEST(PasswordTest, numbers) {
	Password my_password;
	bool result = my_password.has_mixed_case("12321312");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, null_character) {
	Password my_password;
	bool result = my_password.has_mixed_case("\0");
	ASSERT_EQ(false, result);
}