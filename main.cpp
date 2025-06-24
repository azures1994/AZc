#include <iostream>

#include "file/file.h"

int test_file(){

    AZc::file::mkdir("test");

    return 0;
}

int main(int, char**){
    std::cout << "Hello, from AZc!\n";

    test_file();

    return 0;
}
