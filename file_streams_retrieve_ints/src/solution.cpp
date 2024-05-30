#include "solution.hpp"

#include <fstream>

std::vector<int> get_ints_from_file(std::string file_name){
    std::ifstream ifs {file_name};
    if(!ifs.is_open()){
        throw std::runtime_error("Failed to open file");
    }

    std::vector<int> tmp {};
    int nextInt = 0;
    while(ifs.good()){
        ifs >> nextInt;
        if(ifs.bad()){
            break;
        } else if(ifs.fail()){
            ifs.clear();
            ifs.ignore(1, '\n');
        } else {
            tmp.push_back(nextInt);
        }
    }
    return tmp;
}