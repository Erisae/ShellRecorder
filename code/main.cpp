#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>


class InputParser{
    public:
        InputParser (int &argc, char **argv){
            for (int i=1; i < argc; ++i)
                this->tokens.push_back(std::string(argv[i]));
        }

        const std::string& getCmdOption(const std::string &option) const{
            std::vector<std::string>::const_iterator itr;
            itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
            if (itr != this->tokens.end() && ++itr != this->tokens.end()){
                return *itr;
            }
            static const std::string default_string("./out.txt");
            return default_string;
        }

        bool cmdOptionExists(const std::string &option) const{
            return std::find(this->tokens.begin(), this->tokens.end(), option)
                   != this->tokens.end();
        }
    private:
        std::vector <std::string> tokens;
};


int launchRecord(std::string filename)
{
    std::string cmd;
    std::ofstream outfile;
    outfile.open(filename);
	while(1)
	{
		std::getline(std::cin, cmd);

        // exit with "quit" command
		if(cmd.compare("quit") == 0)
			break;	
        system(cmd.data());
        outfile << cmd.data() << std::endl;
    }
    outfile.close();

    return 0;
}


int launchScript(std::string filenaame)
{
    return 0;
}


int lauchPythonLibrary(std::string filename)
{
    return 0;
}


int main(int argc, char* argv[])
{
    // argument parsing
    InputParser input(argc, argv);

    const std::string &filename = input.getCmdOption("-f");

    if(input.cmdOptionExists("-s"))
    {
        launchScript(filename);
    }

    if(input.cmdOptionExists("-r"))
    {
        launchRecord(filename);
    }

    if(input.cmdOptionExists("-p"))
    {
        lauchPythonLibrary(filename);
    }

    return 0;
}

//TODO: can not change dir
//TODO: how to collect the output from system


/*
reference:
https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c
*/

