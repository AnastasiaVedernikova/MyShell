//
// Created by anastasia on 19.04.17.
//
#include "mkdir.h"
void mkdir(string curr_dir, string a){
    std::vector<std::string> lines;
    boost::split(lines, a, boost::is_any_of(" "));
//    if(lines[0] == "-h" || "--help"){
//        cout<<"create new directory" <<endl;
//    }
    std::size_t found = a.find("/");
    if (found!=std::string::npos) {
        boost::filesystem::create_directories(curr_dir + a);
    } else {
        boost::filesystem::create_directory(curr_dir + a);
    }
}

