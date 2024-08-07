/*

The ORIGINAL CODE is the `C++ File Manager` Source Code.
The INITIAL DEVELOPER is Brace Software Co., DEntisT.

Version: MPL 1.1

The contents of this file are subject to the Mozilla Public License Version 
1.1 the "License"; you may not use this file except in compliance with 
the License. You may obtain a copy of the License at 
http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the
License.

Portions created by the Initial Developer are Copyright (c) 2022
the Initial Developer. All Rights Reserved.

*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <filesystem>
#include <unordered_map>

#include "fminternal.hpp"
#include "fmimpl.hpp"
#include "fmextra.hpp"

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

    flmgr::dir myDir("myDir");

    myDir.create();

    flmgr::file<flmgr::filetype::txt> FileInDir(myDir, "file.txt");

    FileInDir.append_text("tesadasdast");

    //FileInDir.remove();

    //myDir.remove();

    flmgr::dir myPath("lol/test");

    myPath.set_name("lol");
    myPath.create();

    myPath.set_name("lol/test");
    myPath.create();

    flmgr::file<flmgr::filetype::txt> FileInPath(myPath, "file.txt");

    FileInPath.append_text("tesadasdast");

    if(FileInPath.exists())
    {
        std::cout << "exists" << std::endl;
    }
    if(!myPath.exists())
    {
        std::cout << "exists2" << std::endl;
    }
    return 0;
}