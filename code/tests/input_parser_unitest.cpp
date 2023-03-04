#include "../headers/input_parser.h"

#include <gtest/gtest.h>

const int argc1 = 2;
const char **argv1 = {"shellrecorder", "-r"};
const int argc2 = 4;
const char **argv2 = {"shellrecorder", "-r", "-f", "test"};
const int argc3 = 5;
const char **argv3 = {"shellrecorder", "-f", "../tests/test", "-r", "-p"};

namespace {

TEST(getCmdOptionTest, Defalut)
{
    const InputParser parser1(argc1, argv1);
    EXPECT_STREQ(parser1.getCmdOption("-f"), "./out");
}

TEST(getCmdOptionTest, NotEmpty)
{
    const InputParser parser1(argc2, argv2);
    EXPECT_STREQ(parser1.getCmdOption("-f"), "test");

    const InputParser parser2(argc3, argv3);
    EXPECT_STREQ(parser2.getCmdOption("-f"), "../tests/test");
}

TEST(cmdOptionExistsTest, Exists)
{
    const InputParser parser1(argc3, argv3);
    EXPECT_TRUE(parser1.cmdOptionExists("-r"));
    EXPECT_TRUE(parser1.cmdOptionExists("-f"));
}

TEST(cmdOptionExistsTest, NotExists)
{
    const InputParser parser1(argc1, argv1);
    EXPECT_FALSE(parser1.cmdOptionExists("-p"));
    EXPECT_FALSE(parser1.cmdOptionExists("-a"));
}

}