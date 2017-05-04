

#ifndef MYSHELL_MV_H
#define MYSHELL_MV_H

#include <boost/filesystem.hpp>
#include <iostream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>


namespace fs = boost::filesystem;

void mv(std::string args, std::string curr_dir);


#endif //MYSHELL_MV_H



