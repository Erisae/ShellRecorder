#ifndef _INPUT_PARSER_
#define _INPUT_PARSER_

#include <string>
#include <vector>

class InputParser{
    public:
        InputParser(int &argc, char **argv);
        const std::string& getCmdOption(const std::string &option);
        bool cmdOptionExists(const std::string &option);
    private:
        std::vector <std::string> tokens;
};

#endif