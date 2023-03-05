// #include "../headers/launch_pylibrary.h"

// #include <string>
// #include <fstream>

// int lauchPythonLibrary()
// {
//     const std::string pyreqCmd, checkExistCmd;
//     std::ofstream outfile;
//     checkExistCmd = "pip show pipreqs > hate.txt 2> warning.txt";
//     system(checkExistCmd.data());
//     outfile.open("warning.txt");
//     if (outfile.eof())
//     {
//         std::string installCmd = "pip install pipreqs";
//         system(installCmd.data());
//     }
//     remove("warning.txt");
//     remove("hate.txt");
//     pyreqCmd = "pipreqs --force .";
//     system(pyreqCmd.data());

//     return 0;
// }