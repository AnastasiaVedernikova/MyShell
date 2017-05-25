//
// Created by anastasia on 27.04.17.
//
#include <sstream>
#include <cstring>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/algorithm/string.hpp>

#include "ls.h"

using namespace std;
namespace fs = boost::filesystem;
int main(int argc, char *argv[])
{


    int count = 0;
    while(argv[++count] != NULL);

    string a = "";

    for(int i=1; i< count; i++){
        string m = argv[i];
        a+= m;
    }

    ls(a, boost::filesystem::current_path().string());

    return 0;

}

