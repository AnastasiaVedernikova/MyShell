//
// Created by anastasia on 27.04.17.
//

#include <sstream>
#include <cstring>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/algorithm/string.hpp>

#include "mv.h"

using namespace std;
namespace fs = boost::filesystem;
int main(int argc, char *argv[])
//done
{
    int count = 0;
    while(argv[++count] != NULL);

    string a = "";
    for(int i=1; i < count; i++){
        string arg1(argv[i]);
        a+= arg1;
        if (i != count-1){
            a+=" ";
        }


    }

    mv(a, boost::filesystem::current_path().string());

    return 0;

}