#include "gtest/gtest.h"
#include "logger.h"

using namespace std;
using namespace SharedLib;

TEST(TestSamples, VerifyGtest) {
	EXPECT_EQ(1, 1);
}
TEST(TestSamples, VerifyGtestTrue){
	EXPECT_TRUE(true);
}

TEST(LoggerTests, Constructor){
	Logger logger("test");
}