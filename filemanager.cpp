#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>

#include "fmstdex.h"
#include "fminternal.h"
#include "fmimpl.h"

namespace fileManager
{
    int main(int argc, char *argv[])
    {
        if(fileManager::__internal::function::check_args("-fmd",argc,argv))
        {
            fileManager::__internal::settings::debug = 1;
        }
        if(fileManager::__internal::function::check_args("-fmv",argc,argv))
        {
            fileManager::__internal::function::vers_info();
        }

        fileManager::__internal::function::init();

        if(fileManager::__internal::function::check_args("-fmT",argc,argv))
        {
            fileManager::__internal::function::testing();
        }

        return 0;
    }
}

// FOR TESTING PURPOSES

int fileManager::__internal::function::testing()
{
    fileManager::file myFile("randomfile.txt");

    fileManager::setfile(myFile);

    fileManager::stdfile::del();

    fileManager::stdfile::append("test");
    fileManager::stdfile::append("3");
    fileManager::stdfile::append("HIII");
    fileManager::stdfile::append("xd");
    
    std::vector<std::string>myvec;
    fileManager::stdfile::read(myvec);

    for(std::vector<std::string>::iterator iter = myvec.begin(); iter < myvec.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    return 0;
}