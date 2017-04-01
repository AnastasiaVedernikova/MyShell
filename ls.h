//
// Created by anastasia on 01.04.17.
//

#ifndef MYSHELL_LS_H
#define MYSHELL_LS_H

#endif //MYSHELL_LS_H
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

#include <string>
#include <boost/range/iterator_range.hpp>
#include <iostream>

using namespace std;
void ls(string a, string curr_dir) {
    std::vector<std::string> lines;
    boost::split(lines, a, boost::is_any_of(" "));
    if(lines[0] == "-h" || "--help"){
        cout<<"list of appropriate files"<<endl;
    }
    fs::path p{a.length() > 1 ? a : curr_dir};
    if (is_directory(p)) {
        for (auto &entry : boost::make_iterator_range(fs::directory_iterator(p), {})) {
            cout << entry << "\n";
        }
    }
}
