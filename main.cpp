#include <iostream>
#include <unistd.h>
#include <sstream>
#include <cstring>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/algorithm/string.hpp>
#include <regex>
#include <fstream>

#include <sys/wait.h>
#include <set>
//done
//anastasia@anastasia-Latitude-3340:~/CLionProjects/MyShell/cmake-build-debug$ export PATH=$PATH:`pwd`





using namespace std;
namespace fs = boost::filesystem;



#if 0
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
#endif

int cd(const vector<string>& in_args) {

    string args = in_args[1];
    if (args == "-h" || args == "--help") {
        cout << "cd - change directory: usage: [full dir], [..], [.], [./local dir]" << endl;
    } else if (chdir(args.c_str()) != 0) {
        perror("Error cd:");
    }

    return 0;
}
int pwd(std::vector<std::string>& a){
    if (a.size() == 1){
    cout << boost::filesystem::current_path().string() << endl;
    }else if (a[1] == "-h" || a[1] == "--help") {
        cout << "pwd: print current directory" << endl;
    }

}
#if 0
    string g = "";
    std::vector<std::string> strs;//arguments
    boost::split(strs, args, boost::is_any_of("/"));


    std::vector<std::string> lines;//curr_dir
    boost::split(lines, boost::filesystem::current_path().string(), boost::is_any_of("/"));


    if (strs[0] == ".."){
        for (int i=1; i<lines.size()-1; i++){

            g+="/";
            g+=lines[i];
        }

        const char * c = boost::filesystem::current_path().string().c_str();
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
            const char * c = boost::filesystem::current_path().string().c_str();
            chdir(c);
        }else{
            cout<<"Error. Try again"<< endl;
        }

    }else if (args == "-h" || args == "--help"){
        cout<<"cd: usage: [full dir], [..], [.], [./local dir]"<<endl;
    }

   else if (fs::is_directory(args)){//full directory
       chdir(args.c_str());
   }else{
        cout<<"no such directory"<<endl;
    }


    return 0;
#endif



int startNewProcess(const char * args[])
{

    pid_t childPid;
    childPid = fork();
    if (childPid == 0)
    {
        execvp(args[0], const_cast<char * const *>(args) );
        cout<<"error"<<endl;
        std::cout << strerror(errno) << std::endl;
    } else if (childPid < 0)
    {
        exit(-1);
    } else {
        waitpid(-1, nullptr, 0);
    }
    return 0 ;
}

int callOuter(const std::vector<std::string>& args)
{
    const char * argv[args.size()+1];
    for (int i = 0; i < args.size(); i++) {
        argv[i] = args[i].c_str();
    }
    argv[args.size()] = nullptr;
    startNewProcess(argv);

    return 0 ;

}

int executeCommand(string input, int status){
    vector<string> splitVec;
        boost::split(splitVec, input, boost::is_space(), boost::token_compress_on);
        string cm = splitVec[0];
        if (cm == "pwd") {
            pwd(splitVec);
        } else if (cm == "cd") {
            cd(splitVec);

        } else if (cm == "exit") {
            if (splitVec[1] == "-h" || splitVec[1] == "--help") {
                cout << "exit[code of ending] finishes work and can return text of ending" << endl;
            } else if (splitVec[1] != "") {
                int c = std::stoi(splitVec[1]);
                exit(c);
            }
            status = 0;
           // break;
        } else if (cm == "help") {
            cout << "help: myrm mycp mymv exit cd pwd myls mymkdir" << endl;
        } else if (boost::starts_with(cm, "#")) {
            status = 1;
           // continue;

        } else {
            callOuter(splitVec);

        }
        cout << "\n";

  return status;
}




int main(int argc, char* argv[], char**env)

{  //.MyShell ttt
    vector<string> splitVec;
    string line = "";
    string input = "";
    ifstream f;
    if (argc>1) {
        f.open(argv[1]);
        if(!f.is_open())
        {
            cerr << "Error " << endl;
            exit(1);
        }
        while (getline(f, line)) {
            cout<<line<<endl;
            int status = executeCommand(line, 1);
            if (status == 0){
                break;
            }else{
                continue;
            }
        }


    }
    else{
        while(true) {
            printf("> ");
            getline(cin, input);
            int status = executeCommand(input, 1);
            if (status == 0){
                break;
            }else{
                continue;
            }

        }

    }


    return 0;

}

