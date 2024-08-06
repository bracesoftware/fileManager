#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>

#include "fmstdex.h"
#include "fminternal.h"
#include "fmimpl.h"

namespace flmgr
{
    int main(int argc, char *argv[])
    {
        if(flmgr::__internal::function::check_args("-fmd",argc,argv))
        {
            flmgr::__internal::settings::debug = 1;
        }
        if(flmgr::__internal::function::check_args("-fmv",argc,argv))
        {
            flmgr::__internal::function::vers_info();
        }

        flmgr::__internal::function::init();

        if(flmgr::__internal::function::check_args("-fmT",argc,argv))
        {
            flmgr::__internal::function::testing();
        }

        return 0;
    }
}

// FOR TESTING PURPOSES

int flmgr::__internal::function::testing()
{
    flmgr::file myFile("randomfile.txt");

    flmgr::setfile(myFile);

    flmgr::stdfile::del();

    flmgr::stdfile::append("test");
    flmgr::stdfile::append("3");
    flmgr::stdfile::append("HIII");
    flmgr::stdfile::append("xd");
    
    std::vector<std::string>myvec;
    flmgr::stdfile::read(myvec);

    for(std::vector<std::string>::iterator iter = myvec.begin(); iter < myvec.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    return 0;
}