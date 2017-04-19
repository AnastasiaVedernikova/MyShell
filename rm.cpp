
#include "rm.h"
using namespace std;
void rm(string file){
    ///home/anastasia/CLionProjects/MyShell
    std::vector<std::string> strs;//arguments
    boost::split(strs, file, boost::is_any_of(" "));
//    if (strs[0] == "-h" || "--help"){
//        cout<<"rm: usage: [-R], [-f], [dir], [file], [file1, file2, file3]"<<endl;
//    }
    if(strs[0] == "-f"){
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
            for (int i = 0; i < strs.size(); i++) {
                if (boost::filesystem::exists(strs[i])) {
                    boost::filesystem::remove(strs[i]);
                }
            }
        }

    }



}
