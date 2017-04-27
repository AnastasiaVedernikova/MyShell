////
//// Created by Olya Korabliova on 12.04.17.
////

#ifndef MYSHELL_CP_H
#define MYSHELL_CP_H

#include <string>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "main.cpp"

namespace fs = boost::filesystem;

void cp(std::string copy_from, std::string copy_to);

#endif //MYSHELL_CP_H
