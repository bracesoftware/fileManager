/*

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

namespace flmgr
{
    namespace __internal
    {
        namespace constants
        {
            int nullint = 0;
            bool nullbool = false;
            std::string nullstr = "";
            char nullchar = '0';
            float nullfloat = 0.0;
        }
        namespace settings
        {
            int debug = 0;
            std::string filename;
        }
        namespace version
        {
            const int major = 0;
            const int minor = 0;
            const int patch = 1;
        }
        namespace function
        {
            int testing(); //used later
            void err(std::string text)
            {
                std::cout << "[flmgr] PROGRAM THREAD @ System error: " << text << std::endl;
            }
            void wrn(std::string text)
            {
                std::cout << "[flmgr] PROGRAM THREAD @ System warning: " << text << std::endl;
            }
            void info(std::string text)
            {
                if(flmgr::__internal::settings::debug == 1)
                {
                    std::cout << "[flmgr] PROGRAM THREAD @ System info: " << text << std::endl;
                }
            }
            void init()
            {
                flmgr::__internal::settings::filename = "null";

                flmgr::__internal::function::info("Init finished.");
            }
            bool check_args(std::string forarg, int argc, char *argv[])
            {
                if(argc > 1) for(int i = 1; i < argc; i++)
                {
                    if(forarg == static_cast<std::string>(argv[i]))
                    {
                        flmgr::__internal::function::info("Argument found.");
                        return true;
                    }
                }
                return false;
            }
            void vers_info()
            {
                std::cout << "File Manager" << flmgr::__internal::constants::nullstr;
                std::cout << flmgr::__internal::version::major<<"."<<flmgr::__internal::version::minor<<"."<<flmgr::__internal::version::patch;
                std::cout << flmgr::__internal::constants::nullstr;
                std::cout << "(c) 2024 Brace Software Co., by DEntisT" << std::endl << std::endl;
            }
            std::vector<std::string> split(const std::string &str, char delimiter)
            {
                std::vector<std::string> tokens;
                std::string token;
                std::stringstream ss(str);

                while (std::getline(ss, token, delimiter))
                {
                    tokens.push_back(token);
                }

                return tokens;
            }
            std::string trim(const std::string &str)
            {
                auto start = str.begin();
                auto end = str.end();

                while(start != end && std::isspace(static_cast<unsigned char>(*start)))
                {
                    ++start;
                }

                if(start == end)
                {
                    return static_cast<std::string>("");
                }
                auto it = end;
                do
                {
                    --it;
                }
                while(it != start && std::isspace(static_cast<unsigned char>(*it)));

                return std::string(start, it + 1);
            }
        }
    }
}