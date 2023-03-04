#include "../headers/launch_record.h"

#include <gtest/gtest.h>

namespace{
    
TEST(recordContentTest, input){
    // redirect input
    std::ifstream commands("record_input.sh");
    std::streambuf* cin_buf = std::cin.rdbuf();
    std::cin.rdbuf(commands.rdbuf());

    // successfully record
    const std::string fn = "record_output";
    EXPECT_TRUE(lauchRecord(fn));

    // right content
    std::string commands_content((std::istreambuf_iterator<char>(commands)),
                             std::istreambuf_iterator<char>());
    std::ifstream records("record_output.sh");
    std::string records_content((std::istreambuf_iterator<char>(records)),
                                std::istreambuf_iterator<char>());
    EXPECT_EQ(commands_content, records_content);

    // right permission
    int result = std::system("/bin/bash -c '[ -x record_output.sh ]'");
    EXPECT_EQ(result, 0);

}


}