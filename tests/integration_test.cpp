#include "../headers/input_parser.h"
#include "../headers/launch_record.h"

#include <fstream>
#include <gtest/gtest.h>

static int argc1 = 4;
static const char* argv1[] = {"shellrecorder", "-r", "-f", "inte_test"};

TEST(IntegrationTest, all)
{
    const InputParser parser1(argc1, argv1);
    const std::string output_file = parser1.getCmdOption("-f");
    // redirect input
    const std::string input_file  = "./record_input.sh";
    std::ifstream commands(input_file);
    std::streambuf* cin_buf = std::cin.rdbuf();
    std::cin.rdbuf(commands.rdbuf());
    if(parser1.cmdOptionExists("-r"))
        launchRecord(output_file.data());

    std::string commands_content((std::istreambuf_iterator<char>(commands)),
                             std::istreambuf_iterator<char>());
    std::ifstream records(output_file);
    std::string records_content((std::istreambuf_iterator<char>(records)),
                                std::istreambuf_iterator<char>());
    EXPECT_STREQ(commands_content.c_str(), records_content.c_str());
}