//
// Created by anastasia on 01.04.17.
//

#include "mv.h"
using namespace std;

void mv(string args, string curr_dir) {
    //done

    std::vector<std::string> strs;//arguments
    boost::split(strs, args, boost::is_any_of(" "));

   // cout<<strs[0]<<endl;
    if (strs[0] == "-h" || strs[0] == "--help"){
        cout<<"mv: usage: [-f], [old_name, new_name], [src, src, dest]"<< endl;
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
     }else if(strs.size() == 2){
        //rename не мовчки
        fs::path src(curr_dir + "/" + strs[0]);
        fs::path dest(curr_dir + "/" + strs[1]);
        string a = strs[0];
        if (boost::filesystem::exists(src)){
            string input = "";
            cout << "Are you sure that you want to rename this file (y/n)?" << endl;
            getline(cin, input);
            if (input == "y") {
                try {
                    fs::rename(src, dest);
                }
                catch (...) {
                    cout << "No such file " << endl;

                }
            }
        }else{
            cout<<"No such file"<<endl;
        }
     }else if(strs.size() > 3 && strs[0] == "-f"){ //              relocate мовчки
         for(int i=1; i<strs.size()-1; i++){
             fs::copy_file(curr_dir+"/"+strs[i], strs[strs.size()-1]+"/"+strs[i], fs::copy_option::overwrite_if_exists);
             boost::filesystem::remove(strs[i]);
         }
     }else if (strs.size()>= 3 && strs[0]!= "-f"){ //            relocate не мовчки
      //  boost::filesystem::exists(strs[i])
        int ex = 0;
        for (int i = 0; i < strs.size(); i++) {
            if (boost::filesystem::exists(boost::filesystem::current_path().string()+"/"+strs[i])){
                ex += 1;
            }
        }
        if (ex == strs.size()) {

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
        }else{
            cout<<"No such file"<<endl;
        }

     }

}

