#include "solution.hpp"

#include <set>

bool ContainsDuplicate(int array[], unsigned int array_size){
    std::set<int> tmp {};
    for(unsigned int i = 0; i < array_size; i++){
        if(tmp.count(array[i]) == 1){
            return true;
        }

        tmp.insert(array[i]);
    }
    return false;
}