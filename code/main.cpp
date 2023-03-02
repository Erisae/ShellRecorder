#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdio>


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
    filename +=  ".sh";
    outfile.open(filename);
	while(1)
	{
		std::getline(std::cin, cmd);

        // exit with "quit" command
		if(cmd.compare("exit") == 0)
			break;	
        system(cmd.data());
        outfile << cmd.data() << std::endl;
    }
    outfile.close();
    std::string chmod_cmd = "chmod +x " + filename;
    system(chmod_cmd.data());

    return 0;
}


int launchScript(std::string filename)
{
    std::string scriptCmd;
    scriptCmd = "script -r -timing=time_log " + filename;
    system(scriptCmd.data());
    return 0;
}

int launchScriptReplay(std::string filename)
{
    std::string replayCmd;
    replayCmd = "script -p " + filename;
    system(replayCmd.data());
    return 0;
}


int lauchPythonLibrary()
{
    std::string pyreqCmd, checkExistCmd;
    std::ofstream outfile;
    checkExistCmd = "pip show pipreqs > hate.txt 2> warning.txt";
    system(checkExistCmd.data());
    outfile.open("warning.txt");
    if (outfile.eof())
    {
        std::string installCmd = "pip install pipreqs";
        system(installCmd.data());
    }
    remove("warning.txt");
    remove("hate.txt");
    pyreqCmd = "pipreqs --force .";
    system(pyreqCmd.data());

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

    if(input.cmdOptionExists("-e"))
    {
        launchScriptReplay(filename);
    }

    if(input.cmdOptionExists("-r"))
    {
        launchRecord(filename);
    }

    if(input.cmdOptionExists("-p"))
    {
        lauchPythonLibrary();
    }

    return 0;
}

//TODO: can not change dir
//TODO: how to collect the output from system


/*
reference:
https://stackoverflow.com/questions/865668/parsing-command-line-arguments-in-c
*/

