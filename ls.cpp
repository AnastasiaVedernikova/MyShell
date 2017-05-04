//
// Created by anastasia on 19.04.17.
//
#include "ls.h"
using namespace std;
int ls(string a, string curr_dir) {
    std::vector<std::string> lines;
    boost::split(lines, a, boost::is_any_of(" "));
    if(lines[0] == "-h" || lines[0] == "--help"){
        cout<<"list of appropriate files"<<endl;
    }
    fs::path p{a.length() > 1 ? a : curr_dir};
    if (is_directory(p)) {
        for (auto &entry : boost::make_iterator_range(fs::directory_iterator(p), {})) {
            cout << entry << "\n";
        }
    }
    return 1;

}

