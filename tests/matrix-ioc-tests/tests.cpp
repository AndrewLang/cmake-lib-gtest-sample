#include "gtest/gtest.h"
#include "logging/logger.h"

using namespace std;
using namespace Matrix;

TEST(TestSamples, VerifyGtest) {
	EXPECT_EQ(1, 1);
}
TEST(TestSamples, VerifyGtestTrue){
	EXPECT_TRUE(true);
}

TEST(LoggerTests, Constructor){
	Logger logger("test");
}

TEST(LoggerTests, Debug) {
	Logger logger("test");
	logger.debug("test message");

}
