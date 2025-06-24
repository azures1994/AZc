#include <iostream>

#include "file.h"

namespace AZc{
namespace file{
int mkdir(const std::string& _path){
    printf("mkdir %s\n", _path.c_str());

    return 0;
}

} // namespcae file
} // namespace AZc
