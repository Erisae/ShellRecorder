#include <gtest/gtest.h>

class MyTestSuite : public ::testing::Test {
protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
  }
};

TEST_F(MyTestSuite, TestCase1) {

}

TEST_F(MyTestSuite, TestCase2) {

}