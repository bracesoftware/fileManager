namespace flmgr
{
    namespace __internal
    {
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
                    if(forarg == (std::string)argv[i])
                    {
                        flmgr::__internal::function::info("Argument found.");
                        return true;
                    }
                }
                return false;
            }
            void vers_info()
            {
                std::cout << "File Manager" << flmgr::stdex::nullstr;
                std::cout << flmgr::__internal::version::major<<"."<<flmgr::__internal::version::minor<<"."<<flmgr::__internal::version::patch;
                std::cout << flmgr::stdex::nullstr;
                std::cout << "(c) 2024 Brace Software Co., by DEntisT" << std::endl << std::endl;
            }
        }
    }
}