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

TEST(PasswordTest, CLC_single_letter_password) {
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, CLC_letters_repeated_at_end) {
	Password my_password;
	int actual = my_password.count_leading_characters("Zoo");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, CLC_uppercase_lowercase_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("ZZzz");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, CLC_number_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("00000001");
	ASSERT_EQ(7, actual);
}

TEST(PasswordTest, CLC_empty_password) {
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, CLC_diff_langauge_letters) {
	Password my_password;
	int actual = my_password.count_leading_characters("оoooooooooo");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, CLC_repeating_spaces) {
	Password my_password;
	int actual = my_password.count_leading_characters("     ");
	ASSERT_EQ(5, actual);
}

TEST(PasswordTest, CLC_repeating_special_characters) {
	Password my_password;
	int actual = my_password.count_leading_characters("&&&&&");
	ASSERT_EQ(5, actual);
}

// TESTS FOR has_mixed_case

TEST(PasswordTest, HMC_empty_case){
	Password my_password;
	bool result = my_password.has_mixed_case("");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, HMC_one_letter) {
	Password my_password;
	bool result = my_password.has_mixed_case("A");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, HMC_only_lowercase){
	Password my_password;
	bool result = my_password.has_mixed_case("aaaaa");
	ASSERT_NE(true, result);
}

TEST(PasswordTest, HMC_only_uppercase){
	Password my_password;
	bool result = my_password.has_mixed_case("AAAA");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, HMC_both_upper_lower) {
	Password my_password;
	bool result = my_password.has_mixed_case("Az");
	ASSERT_EQ(true, result);
}

TEST(PasswordTest, HMC_special_characters) {
	Password my_password;
	bool result = my_password.has_mixed_case("A&&&");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, HMC_upper_lower_special_characters) {
	Password my_password;
	bool result = my_password.has_mixed_case("12\nA&&&zyyyAlllmmm;;\n\0");
	ASSERT_EQ(true, result);
}

TEST(PasswordTest, HMC_numbers) {
	Password my_password;
	bool result = my_password.has_mixed_case("12321312");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, HMC_null_character) {
	Password my_password;
	bool result = my_password.has_mixed_case("\0");
	ASSERT_EQ(false, result);
}

// TESTS FOR SET & AUTHENICATE

TEST(PasswordTest, SA_correct_password) {
	Password my_password;
	my_password.set("correctPassword");
	bool result = my_password.authenticate("correctPassword");
	ASSERT_EQ(true, result);
}

TEST(PasswordTest, SA_another_correct_password) {
	Password my_password;
	my_password.set("cccOrect");
	bool result = my_password.authenticate("cccOrect");
	ASSERT_EQ(true, result);
}

TEST(PasswordTest, SA_invalid_password) {
	Password my_password;
	my_password.set("0");
	bool result = my_password.authenticate("0");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, SA_invalid_length_password) {
	Password my_password;
	my_password.set("777char");
	bool result = my_password.authenticate("777Char");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, SA_invalid_leading_password) {
	Password my_password;
	my_password.set("8888char");
	bool result = my_password.authenticate("8888Char");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, SA_invalid_mixed_case_password) {
	Password my_password;
	my_password.set("notmixedcase");
	bool result = my_password.authenticate("notcorrect");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, SA_invalid_another_mixed_case_password) {
	Password my_password;
	my_password.set("notmixedcase");
	bool result = my_password.authenticate("NOTCORRECT");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, SA_empty_password) {
	Password my_password;
	my_password.set("correctPassword");
	bool result = my_password.authenticate("");
	ASSERT_EQ(false, result);
}

TEST(PasswordTest, SA_previously_used_password) {
	Password my_password;
	my_password.set("correctPassword");
	my_password.set("ChicoCA-95929");
	bool result = my_password.authenticate("ChicoCA-95929");
	ASSERT_EQ(false, result);
}