#include "../headers/launch_record.h"

#include <fstream>
#include <gtest/gtest.h>

const std::string output_file = "./record_output.sh";
const std::string input_file  = "/Users/arika/Desktop/ShellRecorder/code/tests/record_input.sh";
TEST(LaunchRecordTest, Input){
    // redirect input
    std::ifstream commands(input_file);
    std::streambuf* cin_buf = std::cin.rdbuf();
    std::cin.rdbuf(commands.rdbuf());

    // successfully record
    EXPECT_TRUE(launchRecord("./record_output"));
}

TEST(LaunchRecordTest, Content){
    // right content
    std::ifstream commands(input_file);
    std::string commands_content((std::istreambuf_iterator<char>(commands)),
                             std::istreambuf_iterator<char>());
    std::ifstream records(output_file);
    std::string records_content((std::istreambuf_iterator<char>(records)),
                                std::istreambuf_iterator<char>());
    EXPECT_STREQ(commands_content.c_str(), records_content.c_str());
}


TEST(LaunchRecordTest, Permission){
    // right permission
    std::string cmd = std::string("/bin/bash -c '[ -x ") + output_file + std::string(" ]'");
    int result = std::system(cmd.data());
    EXPECT_EQ(result, 0);
}
