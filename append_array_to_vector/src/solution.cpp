#include "solution.hpp"

void AppendArrayToVector(int array[], unsigned int array_size, std::vector<int> &vector){
    for(unsigned int i = 0; i < array_size; i++){
        vector.push_back(array[i]);
    }
}