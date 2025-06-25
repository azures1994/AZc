#include <iostream>
#include <algorithm> // std::replace

#ifdef _WIN32
#include <io.h> // _access
#include <direct.h> // _mkdir
#elif __linux__
#include <unistd.h> // access
#include <sys/stat.h> // mkdir
#endif

#include "file.h"

namespace AZc{
namespace file{

int createDirectory(const std::string& _path){
    printf("--- mkdir %s\n", _path.c_str());
    std::string path = _path;

#ifdef _WIN32
    #define ACCESS(path) _access(path, 0)
    #define MKDIR(path) _mkdir(path)
    const char PATH_SEP = '\\';
    const char N_PATH_SEP = '/';
#elif __linux__
    #define ACCESS(path) access(path, F_OK)
    #define MKDIR(path) mkdir(path, 0777)
    const char PATH_SEP = '/';
    const char N_PATH_SEP = '\\';
#endif

    std::replace(path.begin(), path.end(), N_PATH_SEP, PATH_SEP);

    for(int i = 0; i <= path.size(); i++){
        if((i == path.size()) || (path[i] == PATH_SEP)){
            std::string subPath = path.substr(0, i);

            if(ACCESS(subPath.c_str()) != 0){
                if(MKDIR(subPath.c_str()) != 0){
                    printf("create directory failed: %s\n", subPath.c_str());
                    return -1;
                };
            }
        }
    }

    return 0;
}

} // namespcae file
} // namespace AZc
