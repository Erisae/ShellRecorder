#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <string>
#include <vector>

// class InputParser{};

class InputParser{
    public:
        InputParser (int &argc, const char* argv[]){
            for (int i=1; i < argc; ++i)
                this->tokens.push_back(std::string(argv[i]));
        }
        const std::string& getCmdOption(const std::string &option) const;
        bool cmdOptionExists(const std::string &option) const{
            return std::find(this->tokens.begin(), this->tokens.end(), option)
                   != this->tokens.end();
        }
    private:
        std::vector <std::string> tokens;
};

#endif