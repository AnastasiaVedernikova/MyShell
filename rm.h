//
// Created by anastasia on 01.04.17.
//

#ifndef MYSHELL_RM_H
#define MYSHELL_RM_H

#endif //MYSHELL_RM_H
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <dirent.h>
#include <sstream>
#include <cstring>
#include <vector>
#include <bits/ios_base.h>
#include <ios>
#include <sys/stat.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <dirent.h>
#include <sstream>
#include <cstring>
#include <vector>
#include <boost/bind.hpp>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <algorithm>
#include <map>
#include <string>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
namespace fs = boost::filesystem;

void rm(string file){
    ///home/anastasia/CLionProjects/MyShell
    std::vector<std::string> strs;//arguments
    boost::split(strs, file, boost::is_any_of(" "));
    if (strs[0] == "-h" || "--help"){
        cout<<"rm: usage: [-R], [-f], [dir], [file], [file1, file2, file3]"<<endl;
    }
    else if(strs[0] == "-f"){
        for(int i=0; i<strs.size()+1; i++){
            if(boost::filesystem::exists(strs[i])) {
                boost::filesystem::remove(strs[i]);
            }
            }
    }else if(strs[0] == "-R"){
       // /home/anastasia/CLionProjects/SHELL
        for(int i=0; i<strs.size()+1; i++) {
            if (boost::filesystem::exists(strs[i])) {
                boost::filesystem::remove_all(strs[i]);

            }
        }

    }else{
        string input="";
        cout<<"Are you sure that you want to remove this file(y/n)?"<<endl;
        getline(cin , input);
        if (input == "y") {
            for (int i = 0; i < strs.size() + 1; i++) {
                if (boost::filesystem::exists(strs[i])) {
                    boost::filesystem::remove(strs[i]);
                }
            }
        }

    }



}
