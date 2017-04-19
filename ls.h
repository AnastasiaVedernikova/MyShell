//
// Created by anastasia on 01.04.17.
//

#ifndef MYSHELL_LS_H
#define MYSHELL_LS_H

#include <string>
#include <boost/range/iterator_range.hpp>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

namespace fs = boost::filesystem;
using namespace std;

void ls(string a, string curr_dir);

#endif //MYSHELL_LS_H

