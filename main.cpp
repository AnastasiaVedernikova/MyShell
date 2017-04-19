#include <iostream>
#include <unistd.h>
#include <sstream>
#include <cstring>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/algorithm/string.hpp>

#include "mv.h"
#include "cp.h"
#include "rm.h"
#include "mkdir.h"
#include "ls.h"


using namespace std;
namespace fs = boost::filesystem;


string curr_dir = "/usr/bin";
string a = "";
string cm = "";


void splitString( string line){
    int i = 0;
    while(i != sizeof(line)){
        if(line[i] == ' '){
            cm = line.substr(0,i);
            a = line.substr(i+1, line.length()-1);
            //sizeof(line)
            break;
        }else{
            cm = line;
        }
        i++;
    }
}

int cd(){
    string args = a;

    string g = "";
    std::vector<std::string> strs;//arguments
    boost::split(strs, args, boost::is_any_of("/"));


    std::vector<std::string> lines;//curr_dir
    boost::split(lines, curr_dir, boost::is_any_of("/"));


    if (strs[0] == ".."){
        for (int i=1; i<lines.size()-1; i++){

            g+="/";
            g+=lines[i];
        }
        curr_dir = g;
       // cout<<curr_dir<<endl;

        const char * c = curr_dir.c_str();
        chdir(c);
    }else if (strs[0] == "."){
        for (int i=1; i<lines.size(); i++){
            g+="/";
            g+=lines[i];
        }
        g+="/";
        for(int i = 1; i < strs.size(); i++){
            g+=strs[i];
        }
        if (fs::is_directory(g)){
            curr_dir = g;
            const char * c = curr_dir.c_str();
            chdir(c);
        }else{
            cout<<"Error. Try again"<< endl;
        }

    }else if (args == "-h" || args == "--help"){
        cout<<"cd: usage: [full dir], [..], [.], [./local dir]"<<endl;
    }

   else if (fs::is_directory(args)){//full directory
       chdir(args.c_str());
       curr_dir = args;
   }else{
        cout<<"no such directory"<<endl;
    }


    return 0;

}
int main(int argc, char* argv[], char**env)
{
    string input = "";

    while(true)  {
        printf("> ");
        getline(cin , input);
        splitString(input);

        if (cm == "pwd"){
            if (a == "-h"|| a == "--help"){
                cout << "pwd: print current directory"<<endl;
            }else{
                cout << curr_dir;
//            }else{
//                cout <<"incorrect input"<<endl;
            }
        }
        else if(cm == "cd"){
            cd();

        }else if(cm == "exit"){
            if (a == "-h" || a == "--help"){
                cout<<"exit[code of ending] finishes work and can return text of ending"<< endl;
            }
            else if (a != ""){
                cout << a << endl;
            }
            break;
        }else if(cm == "mv"){
            mv(curr_dir, a);
        }else if(cm == "cp"){
            int pos = a.find(" /");
            string ar = a;
            string from = ar.substr(0, pos);
            string to = ar.substr(pos+1, a.length() - 1);
            cout << "from: " << from << ",   to: " << to << endl;
            cp(from, to);

        }else if(cm == "rm"){
            rm(a);
        }else if(cm == "help"){
            cout<<"help: rm cp mv exit cd pwd ls mkdir"<<endl;

        }else if(cm == "ls"){
            ls(a, curr_dir);
        }else if(cm == "mkdir"){
            mkdir(curr_dir, a);
        }

        cout << "\n";

    }

    return 0;

}

