
#ifndef MYSHELL_RM_H
#define MYSHELL_RM_H

#include <vector>
#include <string>

#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>


namespace fs = boost::filesystem;


int rm(std::string file);

#endif //MYSHELL_RM_H

