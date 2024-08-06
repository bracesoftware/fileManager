namespace flmgr
{
    class file
    {
        private:
            std::string name;
        public:
            file(std::string name)
            {
                this->name=name;
            }
            std::string getHandleName()
            {
                return this->name;
            }
    };
    void setfile(flmgr::file file)
    {
        flmgr::__internal::settings::filename = file.getHandleName();
    }
    namespace stdfile
    {
        //append
        void append(std::string text)
        {
            std::ofstream internal_fileobject(flmgr::__internal::settings::filename, std::ios::app);

            if(internal_fileobject.is_open())
            {
                internal_fileobject << text << std::endl;
                internal_fileobject.close();  // Zatvaranje fajla
            }
            else
            {
                flmgr::__internal::function::err("Unable to open the file.");
            }
        }
        //read
        void read(std::vector<std::string> &dest)
        {
            std::ifstream internal_fileobject(flmgr::__internal::settings::filename);
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
        void del()
        {
            std::ofstream internal_fileobject(flmgr::__internal::settings::filename);
            if(internal_fileobject.is_open())
            {
                internal_fileobject.close();
            }
            else
            {
                flmgr::__internal::function::err("Unable to open the file.");
            }
        }

        /*namespace __deprecated
        {
            //set
            void set(std::string text)
            {
                flmgr::system::wrn("Don't use this - use \"flmgr::config::append()\" instead.");
                std::ofstream internal_fileobject(flmgr::__internal::settings::filename);  // Otvaranje fajla za pisanje
                if(internal_fileobject.is_open())
                {
                    internal_fileobject << text;
                    internal_fileobject.close();  // Zatvaranje fajla
                }
                else
                {
                    flmgr::system::err("Unable to open the file.");
                }
                //return 0;
            }
        }*/
    }
}