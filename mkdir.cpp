//
// Created by anastasia on 19.04.17.
//
#include <iostream>
#include "mkdir.h"
using namespace std;
//void mkdir(string curr_dir, string a){
//    std::vector<std::string> lines;
//    boost::split(lines, a, boost::is_any_of(" "));
////    if(lines[0] == "-h" || "--help"){
////        cout<<"create new directory" <<endl;
////    }
//    std::size_t found = a.find("/");
//    if (found!=std::string::npos) {
//        boost::filesystem::create_directories(curr_dir + a);
//    } else {
//        boost::filesystem::create_directory(curr_dir + a);
//    }
//    cout<<"sec"<<endl;
//}
void mkdir(string curr_dir, string a){
    std::size_t found = a.find("/");
    if (found!=std::string::npos) {
        boost::filesystem::create_directories(curr_dir + a);
    } else {
        boost::filesystem::create_directory(curr_dir + a);
    }
}

