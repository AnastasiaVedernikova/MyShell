//
// Created by anastasia on 01.04.17.
//

#ifndef MYSHELL_MKDIR_H
#define MYSHELL_MKDIR_H

#include <string>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

namespace fs = boost::filesystem;


void mkdir(std::string a,std::string curr_dir);

#endif //MYSHELL_MKDIR_H

