#pragma once

#include <string>
#include <vector>

namespace AZc{
namespace file{

int createDirectory(const std::string& _path);

int searchFiles(std::vector<std::string>& files_, const std::string& rootDir_, const std::string& suffix_, bool recursive_);

} // namespace file
} // namespace AZc
