// #include <example-lib/example-lib.hpp>

#include "gtest/gtest.h"

class TestExampleLib : public ::testing::Test {
  public:
    virtual void SetUp() {}

    virtual void TearDown() {}
};

TEST_F(TestExampleLib, TestIsAllwaysOK) {
    EXPECT_EQ(0, 0);
    return;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
