//
// Created by anastasia on 01.04.17.
//

#include "mv.h"
using namespace std;

void mv(string curr_dir, string args) {
    std::vector<std::string> strs;//arguments
    boost::split(strs, args, boost::is_any_of(" "));

    //if not rename we need to remove(copy(file)->remove)

//    if (strs.size()>3){
//        if (exists(strs[2]))
//            remove (strs[2]);
//        copy_file(curr_dir, strs[strs.size()]);
//    }
//        if (strs[0] == "-f") {
//            fs::path dest(curr_dir + "/" + strs[strs.size()]);
//            try {
//                for (int i = 1; i < strs.size() - 1; i++) {
//                    fs::path src(curr_dir + "/" + strs[i]);
//                    fs::rename(src, dest);
//                }
//            }
//            catch (...) {
//                cout << "No such file " << endl;
//            }
//        }else{
//            string input = "";
//            cout<<"Are you sure that you want to rename this file(y/n)?"<<endl;
//            getline(cin , input);
//            if (input == "y") {
//                fs::path dest(curr_dir + "/" + strs[strs.size()]);
//                try {
//                    for (int i = 1; i < strs.size() - 1; i++) {
//                        fs::path src(curr_dir + "/" + strs[i]);
//                        fs::rename(src, dest);
//                    }
//                }
//                catch (...) {
//                    cout << "No such file " << endl;
//                }
//            }
//
//        }
//    }


//    if (strs[0] == "-h" || "--help"){
//        cout<<"mv: usage: [-f], [src, dest], [firstname, secondname], [src, src, dest]"<<endl;
//    }


     if (strs.size()==3 & strs[0]=="-f") {
        fs::path src(curr_dir + "/" + strs[1]);
        fs::path dest(curr_dir + "/" + strs[2]);
        try {
            fs::rename(src, dest);
        }
        catch (...) {
            cout << "No such file " << endl;

        }
    }else if (strs.size() == 2){
        string input = "";
        cout<<"Are you sure that you want to rename this file(y/n)?"<<endl;
        getline(cin , input);
        if (input == "y") {

            fs::path src(curr_dir + "/" + strs[0]);
            fs::path dest(curr_dir + "/" + strs[1]);

            //src("/home/anastasia/CLionProjects/MyShell/copy_test.txt");
            // dest("copy_test_res.txt");

            try {
                fs::rename(src, dest);
            }
            catch (...) {
                cout << "No such file " << endl;
                // return false;
            }
        }
    }else{
         for(int i=0; i<strs.size()-1; i++){
             fs::copy_file(curr_dir+"/"+strs[i], strs[strs.size()-1]+"/"+strs[i], fs::copy_option::overwrite_if_exists);
             boost::filesystem::remove(strs[i]);
         }
     }

}
