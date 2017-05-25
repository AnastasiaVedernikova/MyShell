//
// Created by anastasia on 19.04.17.
//
#include "ls.h"
//using namespace std;
//int ls(string a, string curr_dir) {
//    std::vector<std::string> lines;
//    boost::split(lines, a, boost::is_any_of(" "));
//    if(lines[0] == "-h" || lines[0] == "--help"){
//        cout<<"list of appropriate files"<<endl;
//    }
//    fs::path p{a.length() > 1 ? a : curr_dir};
//    if (is_directory(p)) {
//        for (auto &entry : boost::make_iterator_range(fs::directory_iterator(p), {})) {
//            cout << entry << "\n";
//        }
//    }
//    return 1;
//
//}
//
// Created by anastasia on 19.04.17.
//

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <regex>


using namespace boost::filesystem;
using namespace std;

int ls(string a, string curr_dir) {
    vector<string> strs;
    boost::split(strs,a,boost::is_any_of(" "));
    path p(strs.size() > 1 && (strs[1].find('/') != std::string::npos) ? strs[1] : curr_dir);
    regex re(strs.size() > 1 && (strs[1].find('/')==std::string::npos)
             && (strs[1].find('-')==std::string::npos)
             ? strs[1]: ".*");
    std::vector<directory_entry> v;
    bool sortit = true;
    struct by_size
    {
        inline bool operator() (const directory_entry& struct1, const directory_entry& struct2)
        {
            if (!is_directory(struct1) && !is_directory(struct2)) {
                return (file_size(struct1) < file_size(struct2));
            } else return false;
        }
    };
    struct by_name
    {
        inline bool operator() (const directory_entry& struct1, const directory_entry& struct2)
        {
            if (!is_directory(struct1) && !is_directory(struct2)) {
                return (struct1.path().filename() < struct2.path().filename());
            } else return false;
        }
    };
    struct by_time
    {
        inline bool operator() (const directory_entry& struct1, const directory_entry& struct2)
        {
            if (!is_directory(struct1) && !is_directory(struct2)) {
                return last_write_time(struct1) < last_write_time(struct2);
            } else return false;
        }
    };
    struct by_ext
    {
        inline bool operator() (const directory_entry& struct1, const directory_entry& struct2)
        {
            if (!is_directory(struct1) && !is_directory(struct2)) {
                return struct1.path().extension() < struct2.path().extension();
            } else return false;
        }
    };
    if (std::find(strs.begin(), strs.end(), "-h") != strs.end() || std::find(strs.begin(), strs.end(), "--help") != strs.end()) {
        cout << "ls [path|mask] [-l] [-h|--help] [--sort=U|S|t|X] [-r] - show files in directory" << endl;
    } else {

        if (is_directory(p)) {
            copy(directory_iterator(p), directory_iterator(), back_inserter(v));
            for(string line: strs) {
                if(line.find("--sort") != string::npos){
                    if(line[7]=='U'){
                        sortit = !sortit;
                    } else if (line[7]=='S'){
                        sort(v.begin(),v.end(),by_size());
                        sortit = !sortit;
                    } else if (line[7]=='t'){
                        sort(v.begin(),v.end(),by_time());
                        sortit = !sortit;
                    } else if (line[7]=='X'){
                        sort(v.begin(),v.end(),by_ext());
                        sortit = !sortit;
                    }
                }
            }
            if (sortit) {
                sort(v.begin(), v.end(), by_name());
            }
            if (std::find(strs.begin(), strs.end(), "-r") != strs.end()) {
                reverse(v.begin(), v.end());
            }
            for (directory_entry entry : v) {
                if (is_directory(entry)) {
                    cout << "/" << entry.path().filename().string() << "\n";
                } else {
                    if (std::find(strs.begin(), strs.end(), "-l") != strs.end()) {
                        std::time_t t = last_write_time(entry);
                        if (regex_match(entry.path().filename().string(), re)) {
                            cout << " " << entry.path().filename().string() << " " <<
                                 file_size(entry) << " " << ctime(&t);
                        }
                    } else {
                        if (regex_match(entry.path().filename().string(), re)) {
                            cout << entry.path().filename().string() << "\n";
                        }
                    }
                }
            }

        }
    }

}


