#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <dirent.h>
#include <sstream>
#include <cstring>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>


using namespace std;
namespace fs = boost::filesystem;


//char *curr_dir = (char *) "/usr/bin";
//char dir[100];
string curr_dir = "/usr/bin";
string a = "";
string cm = "";



void splitString( string line){
    int i = 0;
    while(i != sizeof(line)){
        if(line[i] == ' '){
            cm = line.substr(0,i);
            a = line.substr(i+1, sizeof(line));
            break;
        }else{
            cm = line;
        }
        i++;
    }
}

int cd(){
//    string command;
    string args = a;
   // chdir(args.c_str());

   // boost::filesystem::path aa("/ttt/");
   // fs::path data_dir(fs::current_path());
   // cout<<a<<endl;
    //printf(args.c_str());
    //cout<<fs::is_directory(a)<<endl;
   if (fs::is_directory(args)){
      // cout << boost::filesystem::current_path().string() << endl;
     //  cout<<"p"<<endl;
       chdir(args.c_str());
       curr_dir += args;
   }
//
//   {
//      //cout<<"opo"<<endl;
//       printf("opo");
//boost::filesystem::current_path(a);
//    }else{
//       // cout<<"lol"<<endl;
//        printf("lol");
//    }

    return 0;

}
int main(int argc, char* argv[], char**env)
{
    string input = "";


    while(true)  {
        printf("> ");
        getline(cin , input);
       // cout<<input<<endl;

        splitString(input);

//        cout<<"args: " << a <<endl;
//        cout<<"cmd: " << cm <<endl;



        if (cm == "pwd"){

            cout << curr_dir;
        }
//        else if ( input == "ls"){
//            ls();
//
//        }
        else if(cm == "cd"){
           // cout<<"opo"<<endl;
            cd();

        }else if(cm == "exit"){
            break;
        }

        cout << "\n";

    }

    return 0;

}

