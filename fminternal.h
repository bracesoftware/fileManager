namespace fileManager
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
                std::cout << "[FileManager] PROGRAM THREAD @ System error: " << text << std::endl;
            }
            void wrn(std::string text)
            {
                std::cout << "[FileManager] PROGRAM THREAD @ System warning: " << text << std::endl;
            }
            void info(std::string text)
            {
                if(fileManager::__internal::settings::debug == 1)
                {
                    std::cout << "[FileManager] PROGRAM THREAD @ System info: " << text << std::endl;
                }
            }
            void init()
            {
                fileManager::__internal::settings::filename = "null";

                fileManager::__internal::function::info("Init finished.");
            }
            bool check_args(std::string forarg, int argc, char *argv[])
            {
                if(argc > 1) for(int i = 1; i < argc; i++)
                {
                    if(forarg == (std::string)argv[i])
                    {
                        fileManager::__internal::function::info("Argument found.");
                        return true;
                    }
                }
                return false;
            }
            void vers_info()
            {
                std::cout << fileManager::__internal::version::major<<"."<<fileManager::__internal::version::minor<<"."<<fileManager::__internal::version::patch;
                std::cout << fileManager::stdex::nullstr;
                std::cout << "(c) 2024 Brace Software Co., by DEntisT" << std::endl << std::endl;
            }
        }
    }
}