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


int ls(std::string a, std::string curr_dir);

#endif //MYSHELL_LS_H

