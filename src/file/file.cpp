#include <iostream>
#include <algorithm> // std::replace

#ifdef __linux__
#include <unistd.h> // access
#include <string.h>
#include <sys/stat.h> // mkdir
#include <dirent.h> // opendir, readdir, closedir
#elif _WIN32
#include <io.h> // _access
#include <direct.h> // _mkdir
#endif

#include "file.h"

namespace AZc{
namespace file{

int createDirectory(const std::string& _path){
    printf("--- mkdir %s\n", _path.c_str());
    std::string path = _path;


#ifdef __linux__
    #define ACCESS(path) access(path, F_OK)
    #define MKDIR(path) mkdir(path, 0777)
    const char PATH_SEP = '/';
    const char N_PATH_SEP = '\\';
#elif _WIN32
    #define ACCESS(path) _access(path, 0)
    #define MKDIR(path) _mkdir(path)
    const char PATH_SEP = '\\';
    const char N_PATH_SEP = '/';
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

int searchFiles(std::vector<std::string>& files_, const std::string& rootDir_, const std::string& suffix_, bool recursive_){

    std::string rootDir = rootDir_;
    if(rootDir.back() != '/') rootDir += '/';

#ifdef __linux__
    DIR* dir;
    struct dirent* entry;
    struct stat statbuf;
    
    if((dir = opendir(rootDir.c_str())) == NULL){
        printf("opendir failed!(%s)\n", rootDir.c_str());
        return -1;
    }

    while((entry = readdir(dir)) != NULL){

        if((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0)) continue;

        std::string fullPath = rootDir + entry->d_name;
        if(stat(fullPath.c_str(), &statbuf) == -1){
            printf("Error: stat failed!(%s)\n", fullPath.c_str());
            continue;
        }

        if(S_ISDIR(statbuf.st_mode)){
            if(recursive_){
                int ret = searchFiles(files_, fullPath, suffix_, recursive_);
                if(ret != 0){
                    printf("searchFiles failed!(%s)\n", fullPath.c_str());
                    continue;
                }
            }
        }else if(S_ISREG(statbuf.st_mode)){
            size_t pos = fullPath.find(suffix_, fullPath.length() - suffix_.length());
            if(pos != std::string::npos){
                files_.push_back(fullPath);
            }
        }
    }

    closedir(dir);
#elif _WIN32

#endif

    return 0;
}

} // namespcae file
} // namespace AZc
