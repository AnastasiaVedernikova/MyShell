//
// Created by anastasia on 27.04.17.
//

#include <sstream>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>

#include "mkdir.h"

using namespace std;
namespace fs = boost::filesystem;
int main(int argc, char * argv[])
{//done
    cout<<"i am mkdir"<<endl;
    string a = "";
    string al= argv[1];//directory
    mkdir(al, boost::filesystem::current_path().string());//trabl cd

    return 0;


}


