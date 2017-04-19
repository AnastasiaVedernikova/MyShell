
#ifndef MYSHELL_RM_H
#define MYSHELL_RM_H

#include <vector>
#include <string>

#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
namespace fs = boost::filesystem;

void rm(string file);

#endif //MYSHELL_RM_H

