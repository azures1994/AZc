#include <iostream>

#include "file/file.h"

int test_file(){

    std::string path = "test/a/b//c/d////e\\f/g/";
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
