#include <iostream>

#include "azc.h"

int test_file(){

#ifdef _WIN32
    std::string path = R"(G:\QFile\/temp//20250625//a\b\\c)";
#elif  __linux__
    std::string path = "test/a/b//c/d////e\\f/g/";
#endif
    if(AZc::file::createDirectory(path) != 0){
        printf("createDirectory failed: %s\n", path.c_str());
        return -1;
    }else{
        printf("createDirectory successfully: %s\n", path.c_str());
    }

    return 0;
}

int main(int, char**){
    std::cout << "Hello, from AZc!\n";

    test_file();

    return 0;
}
