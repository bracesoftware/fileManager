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

#define __flmgr_filetype_txt 0
#define __flmgr_filetype_ini 1

namespace flmgr
{
    class dir
    {
        private:
            std::string dirname;
        public:
            dir(std::string dirname)
            {
                this->dirname=dirname;
            }
            //funcs - getters and setters
            void set_name(std::string dirname)
            {
                this->dirname=dirname;
            }
            std::string get_name()
            {
                return (this->dirname) + "/";
            }
            void create()
            {
                std::filesystem::path dirpath = this->dirname;
                try
                {
                    std::filesystem::create_directory(dirpath);
                }
                catch(const std::filesystem::filesystem_error *error)
                {
                    flmgr::__internal::function::err("File system error - " + (std::string)error->what());
                }
            }
            void remove()
            {
                std::filesystem::path dirpath = this->dirname;
                try
                {
                    std::filesystem::remove(dirpath);
                }
                catch(const std::filesystem::filesystem_error *error)
                {
                    flmgr::__internal::function::err("File system error - " + (std::string)error->what());
                }
                
            }
    };
    namespace filetype
    {
        const int txt = __flmgr_filetype_txt;
        const int ini = __flmgr_filetype_ini;
    }
    namespace filepath
    {
        const std::string null = "";
    }
    template<const int t_filetype> class file
    {
        private:
            std::string filename;
            int filetype = (int)t_filetype;
            std::string filepath = flmgr::filepath::null;
        public:
            file(std::string filename)
            {
                this->filepath=flmgr::filepath::null;
                this->filename=filename;
            }
            file(std::string filepath, std::string filename)
            {
                this->filepath=filepath;
                this->filename=filename;
            }
            //funcs - getters and setters
            void set_name(std::string filename)
            {
                this->filename=filename;
            }
            std::string get_name()
            {
                return (std::string)(this->filepath + this->filename);
            }
            //management
            void overwrite_text(std::string text)
            {
                if(this->filetype != __flmgr_filetype_txt)
                {
                    flmgr::__internal::function::wrn("Invalid file type for this operation.");
                }
                std::ofstream internal_fileobject((std::string)(this->filepath + this->filename));
                if(internal_fileobject.is_open())
                {
                    internal_fileobject << text;
                    internal_fileobject.close();
                }
                else
                {
                    flmgr::__internal::function::err("Unable to open the file.");
                }
            }
            void append_text(std::string text)
            {
                if(this->filetype != __flmgr_filetype_txt)
                {
                    flmgr::__internal::function::wrn("Invalid file type for this operation.");
                }
                std::ofstream internal_fileobject((std::string)(this->filepath + this->filename), std::ios::app);

                if(internal_fileobject.is_open())
                {
                    internal_fileobject << text << std::endl;
                    internal_fileobject.close();
                }
                else
                {
                    flmgr::__internal::function::err("Unable to open the file.");
                }
            }
            void read_text(std::vector<std::string> &dest)
            {
                if(this->filetype != __flmgr_filetype_txt)
                {
                    flmgr::__internal::function::wrn("Invalid file type for this operation.");
                }
                std::ifstream internal_fileobject((std::string)(this->filepath + this->filename));
                if(internal_fileobject.is_open())
                {
                    std::string line;

                    while(std::getline(internal_fileobject, line))
                    {
                        dest.push_back(line);
                    }
                    internal_fileobject.close();
                }
                else
                {
                    flmgr::__internal::function::err("Unable to open the file.");
                }
            }
            void read_line(int line, std::string &dest)
            {
                if(this->filetype != __flmgr_filetype_txt)
                {
                    flmgr::__internal::function::wrn("Invalid file type for this operation.");
                }
                std::ifstream internal_fileobject((std::string)(this->filepath + this->filename));
                if(internal_fileobject.is_open())
                {
                    std::string readtext;
                    int linenumber = 1;

                    while(std::getline(internal_fileobject, readtext))
                    {
                        if(linenumber == line)
                        {
                            dest = readtext;
                            break;
                        }
                        linenumber++;
                    }
                    internal_fileobject.close();
                }
                else
                {
                    flmgr::__internal::function::err("Unable to open the file.");
                }
            }
            void remove_content()
            {
                std::ofstream internal_fileobject((std::string)(this->filepath + this->filename));
                if(internal_fileobject.is_open())
                {
                    internal_fileobject.close();
                }
                else
                {
                    flmgr::__internal::function::err("Unable to open the file.");
                }
            }
            void set_key(std::string key, std::string value)
            {
                if(this->filetype != __flmgr_filetype_ini)
                {
                    flmgr::__internal::function::wrn("Invalid file type for this operation.");
                }
                std::ofstream internal_fileobject((std::string)(this->filepath + this->filename), std::ios::app);

                if(internal_fileobject.is_open())
                {
                    internal_fileobject << key << "=" << value << std::endl;
                    internal_fileobject.close();
                }
                else
                {
                    flmgr::__internal::function::err("Unable to open the file.");
                }
            }
            std::string get_key(std::string key)
            {
                if(this->filetype != __flmgr_filetype_ini)
                {
                    flmgr::__internal::function::wrn("Invalid file type for this operation.");
                }
                std::ifstream internal_fileobject((std::string)(this->filepath + this->filename));
                if(internal_fileobject.is_open())
                {
                    std::string line;
                    std::vector<std::string>linesplit;

                    while(std::getline(internal_fileobject, line))
                    {
                        linesplit.clear();
                        linesplit = flmgr::__internal::function::split(line,'=');
                        if(linesplit[0] == key)
                        {
                            return linesplit[1];
                        }
                    }
                    internal_fileobject.close();
                }
                else
                {
                    flmgr::__internal::function::err("Unable to open the file.");
                }
                return flmgr::stdex::nullstr;
            }
            std::string get_keys(std::unordered_map<std::string, std::string> &dest)
            {
                if(this->filetype != __flmgr_filetype_ini)
                {
                    flmgr::__internal::function::wrn("Invalid file type for this operation.");
                }
                std::ifstream internal_fileobject((std::string)(this->filepath + this->filename));
                if(internal_fileobject.is_open())
                {
                    std::string line;
                    std::vector<std::string>linesplit;

                    while(std::getline(internal_fileobject, line))
                    {
                        linesplit.clear();
                        linesplit = flmgr::__internal::function::split(line,'=');
                        dest[linesplit[0]] = linesplit[1];
                    }
                    internal_fileobject.close();
                }
                else
                {
                    flmgr::__internal::function::err("Unable to open the file.");
                }
                return flmgr::stdex::nullstr;
            }
            void remove()
            {
                std::filesystem::path filepath = (std::string)(this->filepath + this->filename);

                try
                {
                    std::filesystem::remove(filepath);
                }
                catch(const std::filesystem::filesystem_error *error)
                {
                    flmgr::__internal::function::err("File system error - " + (std::string)error->what());
                }
            }
    };
}