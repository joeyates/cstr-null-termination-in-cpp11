#include <gtest/gtest.h>
#include <string>
#include <string.h>

using namespace std;

TEST(CStringNullTermination, BuildFromChars) {
  string buildFromChars;
  buildFromChars.push_back('c');

  ASSERT_EQ(1, strlen(buildFromChars.c_str()));
}

TEST(CStringNullTermination, FromCharPointer) {
  string fromCharPointer = "Hello World";
  ASSERT_EQ(11, strlen(fromCharPointer.c_str()));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int result = -1;
  return RUN_ALL_TESTS();
}
