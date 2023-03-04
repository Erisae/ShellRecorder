#include "./headers/input_parser.h"
#include "./headers/launch_record.h"
#include "./headers/launch_script.h"
#include "./headers/launch_replay.h"
#include "./headers/launch_pylibrary.h"

#include <string>

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

