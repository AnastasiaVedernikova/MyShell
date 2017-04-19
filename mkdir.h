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
using namespace std;

void mkdir(string curr_dir, string a);

#endif //MYSHELL_MKDIR_H

