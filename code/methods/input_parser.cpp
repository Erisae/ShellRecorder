#include "../headers/input_parser.h"

#include <vector>
#include <string>

// class InputParser{
//     public:
//         InputParser (int &argc, const char* argv[]){
//             for (int i=1; i < argc; ++i)
//                 this->tokens.push_back(std::string(argv[i]));
//         }

//         const std::string& getCmdOption(const std::string &option) const{
//             std::vector<std::string>::const_iterator itr;
//             itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
//             if (itr != this->tokens.end() && ++itr != this->tokens.end()){
//                 return *itr;
//             }
//             static const std::string default_string("./out");
//             return default_string;
//         }

//         bool cmdOptionExists(const std::string &option) const{
//             return std::find(this->tokens.begin(), this->tokens.end(), option)
//                    != this->tokens.end();
//         }
//     private:
//         std::vector <std::string> tokens;
// };

// InputParser::InputParser(int &argc, const char* argv[]){
//     for (int i=1; i < argc; ++i)
//         this->tokens.push_back(std::string(argv[i]));
// }

const std::string& InputParser::getCmdOption(const std::string &option) const{
    std::vector<std::string>::const_iterator itr;
    itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
    if (itr != this->tokens.end() && ++itr != this->tokens.end()){
        return *itr;
    }
    static const std::string default_string("./out");
    return default_string;
}

