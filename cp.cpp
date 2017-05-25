//
// Created by anastasia on 19.04.17.
//
#include "cp.h"

using namespace std;

void cp(string copy_from, string copy_to) {
    //done
    string s_path, d_path;
    string source_file_name, dest_file_name;
    vector<string> lst;         //vector of file names to copy
    string s_directory, d_directory;

    size_t num_of_slash_from = count(copy_from.begin(), copy_from.end(), '/');  //calculate amount of / in copy_from
    size_t num_of_slash_to = count(copy_to.begin(), copy_to.end(), '/');    //calculate amount of / in copy_to
    size_t num_of_br = count(copy_from.begin(), copy_from.end(), '{') +
                       count(copy_from.begin(), copy_from.end(), '}');     //calculate amount of {} in copy_from


    if (num_of_slash_from == 0) {       //address (copy_from) entered without directory
        s_path = boost::filesystem::current_path().string();
        source_file_name = copy_from;
    }

    else {
        vector<string> source_path;
        boost::split(source_path, copy_from, boost::is_any_of("/"));
        source_file_name = source_path[source_path.size() - 1];

        for (int i = 1; i < source_path.size() - 1; i++) {       // directory to copy from
            s_path += '/';
            s_path += source_path[i];
        }
    }

    if (num_of_slash_to == 0) {       //address (copy_to) entered without directory
        d_path = boost::filesystem::current_path().string();
        dest_file_name = copy_to;
    }


    else {
        vector<string> destination_path;
        boost::split(destination_path, copy_to, boost::is_any_of("/"));
        for (int i = 1; i < destination_path.size() - 1; i++) {      // directory to copy in
            d_path += '/';
            d_path += destination_path[i];
        }
        dest_file_name = destination_path[destination_path.size() - 1];
    }


    if (num_of_br == 2) {       // copy_from contains more than one file to copy
        string s1;
        string s = source_file_name.substr(1, source_file_name.length() - 2);
        for (int i = 0; i <= s.length(); ++i) {
            if (s[i] != ' ' && i != s.length()) {
                s1 += s[i];             // form a string - name of a file to add to lst
            } else {
                lst.push_back(s1);      // vector that contains all names of files to be copied
                s1 = "";
            }
        }
    }

    if (lst.size() != 0) {
        for (size_t i = 0; i < lst.size(); ++i) {
            s_directory = s_path + "/" + lst[i];         // form full directory to the file
            d_directory = d_path + "/" + lst[i];         // form full directory to the copied file

            fs::path source(s_directory);
            fs::path destination(d_directory);
            fs::copy_file(source, destination, fs::copy_option::overwrite_if_exists);
        }
    }
    else {
        s_directory = s_path + "/" + source_file_name;         // form full directory to the file
        d_directory = d_path + "/" + dest_file_name;         // form full directory to the copied file

        fs::path source(s_directory);
        fs::path destination(d_directory);
        fs::copy_file(source, destination, fs::copy_option::overwrite_if_exists);
    }
    cout << "File successfully copied!" << endl;
}