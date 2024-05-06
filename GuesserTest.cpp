/**
 * Unit Tests for the class
 **/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
protected:
	GuesserTest() {}		   // constructor runs before each test
	virtual ~GuesserTest() {}  // destructor cleans up after tests
	virtual void SetUp() {}	   // sets up before each test (after constructor)
	virtual void TearDown() {} // clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
	ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GuesserTest, Empty_string)
{
	Guesser my_guesser("");
	bool actual = my_guesser.match("");
	ASSERT_FALSE(actual);
}

TEST(GuesserTest, matching_test)
{
	Guesser my_guesser("abc");
	bool actual = my_guesser.match("abc");
	ASSERT_EQ(0, actual);
}

TEST(GuesserTest, incorrect_match)
{
	Guesser my_guesser("abc");
	bool actual = my_guesser.match("ab");
	ASSERT_EQ(2, actual);
}

TEST(GuesserTest, remain_test)
{
	Guesser my_guesser("");
	ASSERT_EQ(3, my_guesser.remaining());
}

TEST(GuesserTest, Amount_guess)
{
	Guesser my_guesser("secret");
	my_guesser.match("first");
	my_guesser.match("second");
	my_guesser.match("thrid");
	ASSERT_EQ(0, my_guesser.remaining());
}

TEST(GuesserTest, Case_sen)
{
	Guesser my_guesser("secret");
	bool actual = my_guesser.match("Secret");
	ASSERT_EQ(0, actual);
}

// TEST(GuesserTest, distance_string) {
// 	Guesser my_guesser("secret");
// 	int actual = my_guesser.distance("secret");
// 	ASSERT_EQ(3, actual);
// }