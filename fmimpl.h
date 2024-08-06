#define __flmgr_filetype_txt 0
#define __flmgr_filetype_ini 1

namespace flmgr
{
    namespace filetype
    {
        const int txt = __flmgr_filetype_txt;
        const int ini = __flmgr_filetype_ini;
    }
    template<const int t_filetype> class file
    {
        private:
            std::string filename;
            int filetype = (int)t_filetype;
        public:
            file(std::string filename)
            {
                this->filename=filename;
            }
            //funcs - getters and setters
            void set_name(std::string filename)
            {
                this->filename=filename;
            }
            std::string get_name()
            {
                return this->filename;
            }
            //management
            void overwrite_text(std::string text)
            {
                if(this->filetype != __flmgr_filetype_txt)
                {
                    flmgr::__internal::function::wrn("Invalid file type for this operation.");
                }
                std::ofstream internal_fileobject(this->filename);
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
                std::ofstream internal_fileobject(this->filename, std::ios::app);

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
                std::ifstream internal_fileobject(this->filename);
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
                std::ifstream internal_fileobject(this->filename);
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
                std::ofstream internal_fileobject(this->filename);
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
                std::ofstream internal_fileobject(this->filename, std::ios::app);

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
                std::ifstream internal_fileobject(this->filename);
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
                std::ifstream internal_fileobject(this->filename);
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
    };
}