#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <unordered_map>

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
    flmgr::file<flmgr::filetype::txt> myFile("randomfile.txt");

    myFile.remove_content();

    myFile.append_text("LOL");
    myFile.append_text("xd");
    myFile.append_text("---");
    myFile.append_text("LOL");
    myFile.append_text("4");

    myFile.overwrite_text("mytect\n");
    myFile.append_text("3");
    myFile.append_text("6");
    
    std::vector<std::string>myvec;
    myFile.read_text(myvec);

    for(std::vector<std::string>::iterator iter = myvec.begin(); iter < myvec.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    flmgr::file<flmgr::filetype::ini> myConfig("mycfg.ini");

    myConfig.remove_content();
    myConfig.set_key("myKey","1");
    myConfig.set_key("3","1");
    myConfig.set_key("myKey","1");
    myConfig.set_key("4Q53","1");
    myConfig.set_key("53","hello world");

    std::cout << myConfig.get_key("53") << std::endl;

    std::unordered_map<std::string, std::string>myMap;
    myConfig.get_keys(myMap);

    for(auto &i : myMap)
    {
        std::cout << i.first << "=" << i.second << std::endl;
    }

    myFile.append_text("TEST");
    std::string line;
    myFile.read_line(4,line);
    std::cout << "line content is : '" << line << "'" << std::endl;
    myFile.read_line(1,line);
    std::cout << "line content is : '" << line << "'" << std::endl;

    myFile.read_line(5,line);
    std::cout << "line content is : '" << line << "'" << std::endl;

    return 0;
}