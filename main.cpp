#include <iostream>

#include "azc.h"

int test_file(){

printf("\n#######################1. AZc::file::createDirectory #######################\n");
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

printf("\n#######################2. AZc::file::searchFiles ###########################\n");

#ifdef __linux__
    std::string rootDir = "/e/QFile/QCode2/AZc";
#elif _WIN32
    std::string rootDir = R"(E:\QFile\QCode\BSJ\ADAS2\adas\common)";
#endif

    std::vector<std::string> files;
    int ret2 = 0;
        
    ret2 = AZc::file::searchFiles(files, rootDir, ".cpp", true);
    if(ret2 != 0){
        printf("searchFiles failed!(%s)\n", rootDir.c_str());
        return -2;
    }

    ret2 = AZc::file::searchFiles(files, rootDir, ".h", true);
    if (ret2 != 0) {
        printf("searchFiles failed!(%s)\n", rootDir.c_str());
        return -2;
    }

    for(const auto& file : files) std::cout << file << std::endl;

    return 0;
}

int test_cv(){ 

    AZc::cv::Rect rect1(0, 0, 100, 100);
    AZc::cv::Rect rect2(50, 50, 50, 50);
    float iou = AZc::cv::clacIOU(rect1, rect2);
    printf("iou: %.2f\n", iou);

    return 0;
}
int main(int, char**){
    std::cout << "Hello, from AZc!\n";

    // test_file();

    test_cv();

    return 0;
}
