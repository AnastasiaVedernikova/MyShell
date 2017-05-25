


//using namespace std;
//namespace fs = boost::filesystem;
//
//int main(int argc, char *argv[]) {
//
//    int c = 0;
//    while(argv[++c] != NULL);
//
//    string a = "";
//
//    for(int i=1; i< c; i++){
//        string m = argv[i];
//        a+= m;
//        a+=" ";
//    }
//
//    long br_num = count(a.begin(), a.end(), '{') + count(a.begin(), a.end(), '}');
//    vector<string> strs;
//    string answer;
//    locale loc;
//
//
//    boost::split(strs, a, boost::is_any_of(" "));
//    if (strs[0] == "-h" || strs[0] == "--help") {
//        cout << "cp help: \n\t-f\t\t-force copy;\n"
//                "Examples:\n"
//                "\tcp /directory_copyfrom/filename /directory_copyin/filename_of_copy\n"
//                "\tcp /directory_copyfrom/{filename1 .. filenameN} /directory_copyin/\n"
//                "\n\t~ uses current directory:\n"
//                "\tcp /directory_copyfrom/filename filename_of_copy\n"
//                "\tcp filename filename_of_copy\n"
//                "\tcp filename /directory_copyto/filename_of_copy\n"
//                "\tcp {filename1 .. filenameN} /directory_copyin/\n"
//                "Do not forget about the extension of a file! Otherwise copied file will be empty!\n" << endl;
//
//    }
//    if (strs[1] == "-f" || strs[0] == "-f") {
//        answer = "y";
//    } else {
//        cout << "Do you really want to copy file(s)? (y/n)" << endl;
//        cin >> answer;
//    }
//
//    strs.erase(remove(strs.begin(), strs.end(), "-h"), strs.end());
//    strs.erase(remove(strs.begin(), strs.end(), "--help"), strs.end());
//    strs.erase(remove(strs.begin(), strs.end(), "-f"), strs.end());
//
//    string ar;
//
//    for (size_t i = 0; i < strs.size(); ++i) {
//        if (i != 0)
//            ar += ' ';
//        ar += strs[i];
//    }
//
//    for (size_t i = 0; i < answer.length(); ++i) {
//        answer[i] = tolower(answer[i], loc);
//    }
//
//    if (answer == "y" || answer == "yes") {
//        if (br_num != 2 && br_num != 0) {
//            cout << "Input Error! Try again!" << endl;
//        } else {
//            int pos;
//            if (br_num == 2) {
//                pos = ar.find("}") + 1;
//            } else if (br_num == 0) {
//                pos = ar.find(" ");
//            }
//            string from = ar.substr(0, pos);
//            string to = ar.substr(pos + 1, ar.length() - 1);
//            cp(from, to);
//        }
//    }
//    return 0;
//}
#include <sstream>
#include <cstring>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <algorithm>
#include "cp.h"
//#include "cp.cpp"



using namespace std;
namespace fs = boost::filesystem;

int main(int argc, char *argv[]) {

    int c = 0;
    while(argv[++c] != NULL);

    string a = "";

    for(int i = 1; i < c; i++){
        string m = argv[i];
        a += m;
        a += " ";
    }

    if (!boost::filesystem::exists(argv[1]) && argv[1]!="-h" && argv[1]!="--help" && argv[1]!="f"){
        cout<<"No such directory!"<<endl;
        exit(1);
    }
    if(!boost::filesystem::exists(argv[2]) && argv[1]=="f"){
        cout<<"No such directory!"<<endl;
        exit(1);
    }

    long br_num = count(a.begin(), a.end(), '{') + count(a.begin(), a.end(), '}');
    vector<string> strs;
    string answer;
    locale loc;


    boost::split(strs, a, boost::is_any_of(" "));
    if (find(strs.begin(), strs.end(), "-h") != strs.end() ||
        find(strs.begin(), strs.end(), "--help") != strs.end()) {
        cout << "\t-f\t\t-force copy;\n"
                "Examples:\n"
                "\tcp /directory_copyfrom/filename /directory_copyin/filename_of_copy\n"
                "\tcp /directory_copyfrom/{filename1 .. filenameN} /directory_copyin/\n"
                "\n\t~ uses current directory:\n"
                "\tcp /directory_copyfrom/filename filename_of_copy\n"
                "\tcp filename filename_of_copy\n"
                "\tcp filename /directory_copyto/filename_of_copy\n"
                "\tcp {filename1 .. filenameN} /directory_copyin/\n"
                "Do not forget about the extension of a file! Otherwise copied file will be empty!\n" << endl;

    }
    if (find(strs.begin(), strs.end(), "-f") != strs.end()) {
        // strs contains "-f"
        answer = "y";
    }

    strs.erase(remove(strs.begin(), strs.end(), "-h"), strs.end());
    strs.erase(remove(strs.begin(), strs.end(), "--help"), strs.end());
    strs.erase(remove(strs.begin(), strs.end(), "-f"), strs.end());

    if (strs.size() > 0 && answer != "y"){

        cout << "Do you really want to copy file(s)? (y/n)" << endl;
        cin >> answer;
    }

    string ar;

    for (size_t i = 0; i < strs.size(); ++i) {
        if (i != 0)
            ar += ' ';
        ar += strs[i];
    }

    for (size_t i = 0; i < answer.length(); ++i) {
        answer[i] = tolower(answer[i], loc);
    }

    if (answer == "y" || answer == "yes") {
        if (br_num != 2 && br_num != 0) {
            cout << "Input Error! Try again!" << endl;
        } else {
            int pos;
            if (br_num == 2) {
                pos = ar.find("}") + 1;
            } else if (br_num == 0) {
                pos = ar.find(" ");
            }
            string from = ar.substr(0, pos);
            string to = ar.substr(pos + 1, ar.length() - 1);
            cp(from, to);
        }
    }
    return 0;
}