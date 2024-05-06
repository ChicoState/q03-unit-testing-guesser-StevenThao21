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
	Guesser my_guesser("Secret Word");
	int actual = my_guesser.match("");
	ASSERT_EQ(0, actual);
}

TEST(GuesserTest, Matching_test_Correct)
{
	Guesser my_guesser("Secret");
	int actual = my_guesser.match("Secret");
	ASSERT_EQ(1, actual);
}

TEST(GuesserTest, Empty_string_test)
{
	Guesser my_guesser("");
	ASSERT_EQ(3, my_guesser.remaining());
}

TEST(GuesserTest, remaining_test)
{
	Guesser my_guesser("Secret Word");
	my_guesser.match("First");
	my_guesser.match("Second");
	my_guesser.match("Third");
	ASSERT_EQ(0, my_guesser.remaining());
}

TEST(GuesserTest, Matching_case_sen)
{
	Guesser my_guesser("Secret");
	int actual = my_guesser.match("secret");
	ASSERT_EQ(0, actual);
}

// In order for me to test the distance I have to move the distance from private to public in the .h file
// TEST(GuesserTest, distance_string)
// {
// 	Guesser my_guesser("Secret Word");
// 	int actual = my_guesser.distance("Secret");
// 	ASSERT_EQ(3, actual);
// }