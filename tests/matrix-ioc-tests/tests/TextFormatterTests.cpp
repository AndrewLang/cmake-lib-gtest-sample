#include "gtest/gtest.h"
#include "common/TextFormatter.h"

using namespace std;
using namespace Matrix;

TEST(TextFormatterTests, Constructor) {
	TextFormatter formatter;
	formatter.format("this", "is", "test");
	EXPECT_EQ(1, 1);
}