#include "../headers/launch_record.h"

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

bool launchRecord(const std::string& file)
{
    std::string cmd;
    const std::string filename = file + std::string(".sh");
    std::ofstream outfile(filename);

	while(1)
	{
		std::getline(std::cin, cmd);

        // exit with "exit" command
		if(cmd.compare("exit") == 0 || std::cin.eof())
        {
            outfile << cmd.data();
			break;	
        }
        system(cmd.data());
        outfile << cmd.data() << std::endl;
    }
    outfile.close();
    std::__fs::filesystem::perms perm = std::__fs::filesystem::perms::all;
    std::__fs::filesystem::permissions(filename, perm);

    return true;
}