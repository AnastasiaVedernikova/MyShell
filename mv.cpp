//
// Created by anastasia on 01.04.17.
//

#include "mv.h"
using namespace std;

void mv(string curr_dir, string args) {

    std::vector<std::string> strs;//arguments
    boost::split(strs, args, boost::is_any_of(" "));

    if (strs[0] == "-h" || strs[0] == "--help"){
        cout<<"mv: usage: [-f], [src, dest], [firstname, secondname], [src, src, dest]"<<endl;
    }
    else if (strs.size()==3 & strs[0]=="-f") {                    //rename мовчки
         fs::path src(curr_dir + "/" + strs[1]);
         fs::path dest(curr_dir + "/" + strs[2]);
         try {
             fs::rename(src, dest);
         }
         catch (...) {
             cout << "No such file " << endl;

         }
     }else if(strs.size() == 2){                             //rename не мовчки
         string input = "";
         cout << "Are you sure that you want to rename this file (y/n)?" << endl;
         getline(cin, input);
         if (input == "y") {
             fs::path src(curr_dir + "/" + strs[0]);
             fs::path dest(curr_dir + "/" + strs[1]);
             try {
                 fs::rename(src, dest);
             }
             catch (...) {
                 cout << "No such file " << endl;

             }
         }
     }else if(strs.size() > 3 && strs[0] == "-f"){ //              relocate мовчки
         for(int i=1; i<strs.size()-1; i++){
             fs::copy_file(curr_dir+"/"+strs[i], strs[strs.size()-1]+"/"+strs[i], fs::copy_option::overwrite_if_exists);
             boost::filesystem::remove(strs[i]);
         }
     }else if (strs.size()>= 3 && strs[0]!= "-f"){ //            relocate не мовчки
         string input = "";
         cout << "Are you sure that you want to relocate files(y/n)?" << endl;
         getline(cin, input);
         if (input == "y") {
             for (int i = 0; i < strs.size() - 1; i++) {
                 fs::copy_file(curr_dir + "/" + strs[i], strs[strs.size() - 1] + "/" + strs[i],
                               fs::copy_option::overwrite_if_exists);
                 boost::filesystem::remove(strs[i]);

             }
         }

     }

}
