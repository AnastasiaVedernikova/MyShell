//
// Created by anastasia on 01.04.17.
//


#ifndef MYSHELL_CP_H
#define MYSHELL_CP_H

#include <string>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
//#include "main.cpp"

namespace fs = boost::filesystem;

void cp(std::string copy_from, std::string copy_to);
//done

#endif //MYSHELL_CP_H