namespace fileManager
{
    void set_filename(std::string filename)
    {
        fileManager::__internal::settings::filename = filename;
    }
   
    //config funcs
    namespace config
    {
        //append
        void append(std::string text)
        {
            std::ofstream internal_fileobject(fileManager::__internal::settings::filename, std::ios::app);

            if(internal_fileobject.is_open())
            {
                internal_fileobject << text << std::endl;
                internal_fileobject.close();  // Zatvaranje fajla
            }
            else
            {
                fileManager::__internal::function::err("Unable to open the file.");
            }
        }
        //read
        void read(std::vector<std::string> &dest)
        {
            std::ifstream internal_fileobject(fileManager::__internal::settings::filename);
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
                fileManager::__internal::function::err("Unable to open the file.");
            }
        }
        void del()
        {
            std::ofstream internal_fileobject(fileManager::__internal::settings::filename);
            if(internal_fileobject.is_open())
            {
                internal_fileobject.close();
            }
            else
            {
                fileManager::__internal::function::err("Unable to open the file.");
            }
        }

        /*namespace __deprecated
        {
            //set
            void set(std::string text)
            {
                fileManager::system::wrn("Don't use this - use \"fileManager::config::append()\" instead.");
                std::ofstream internal_fileobject(fileManager::__internal::settings::filename);  // Otvaranje fajla za pisanje
                if(internal_fileobject.is_open())
                {
                    internal_fileobject << text;
                    internal_fileobject.close();  // Zatvaranje fajla
                }
                else
                {
                    fileManager::system::err("Unable to open the file.");
                }
                //return 0;
            }
        }*/
    }
}