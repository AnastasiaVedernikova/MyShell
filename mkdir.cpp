//
// Created by anastasia on 19.04.17.
//
#include <iostream>
#include "mkdir.h"
using namespace std;

int mkdir(string curr_dir, string a){
    std::vector<std::string> lines;
    boost::split(lines, a, boost::is_any_of(" "));
    if(a == "-h" || a == "--help"){
        cout<<"creates new directory" <<endl;
    }else {
        std::size_t found = a.find("/");
        if (found != std::string::npos) {
            boost::filesystem::create_directories(curr_dir + "/" + a);
        } else {
            boost::filesystem::create_directory(curr_dir + "/" + a);
        }
    }
    return 1;
}

