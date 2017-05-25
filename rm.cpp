
#include "rm.h"
using namespace std;
int rm(string file){
    //done
    ///home/anastasia/CLionProjects/MyShell
    std::vector<std::string> strs;//arguments
    boost::split(strs, file, boost::is_any_of(" "));


    if (strs[0] == "-h" || strs[0] == "--help"){
        cout<<"rm: usage: [-f], [-R], [dir], [file], [file1, file2, file3]"<<endl;
    }
    else if(strs[0] == "-f" && strs[1] == "-R"){
        for(int i=2; i<strs.size(); i++){//+1
            if(boost::filesystem::exists(boost::filesystem::current_path().string()+"/"+strs[i])) {
                boost::filesystem::remove_all(strs[i]);
            }
        }
    }else if(strs[0] == "-R") {
        // /home/anastasia/CLionProjects/SHELL
        int ex = 0;
        for (int i = 1; i < strs.size(); i++) {//+1
            if (boost::filesystem::exists(boost::filesystem::current_path().string()+"/"+strs[i])){
                ex += 1;
            }
        }
        if (ex == strs.size()-1){
            string input = "";
            cout << "Are you sure that you want to remove this file(y/n)?" << endl;
            getline(cin, input);
            if (input == "y") {
                for (int i = 1; i < strs.size(); i++) {//+1
                    boost::filesystem::remove_all(strs[i]);

                }
            }
        }else{
            cout<<"No such file"<<endl;
        }
    }else if (strs[0]== "-f" && strs[1] != "-R"){
        for(int i=1; i<strs.size(); i++){//+1
            if(boost::filesystem::exists(strs[i]) && !(fs::is_directory(strs[i]))) {
                boost::filesystem::remove(strs[i]);
            }else{
                cout<<"You can not do it. It is directory! Use -R for this reason."<<endl;
            }
        }

    }else{
        int ex = 0;
        for (int i = 0; i < strs.size(); i++) {
            if (boost::filesystem::exists(strs[i]) && !(fs::is_directory(strs[i]))) {
                ex += 1;
            }
        }
        if (ex == strs.size()) {
            string input = "";
            cout << "Are you sure that you want to remove this file(y/n)?" << endl;
            getline(cin, input);
            if (input == "y") {
                for (int i = 0; i < strs.size(); i++) {
                    boost::filesystem::remove(strs[i]);
                }
            }

        }else{
            cout <<"No such file or it is directory. Use -R in case of directory." << endl;

        }

    }
    return 1;




}

