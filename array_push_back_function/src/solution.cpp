#include "solution.hpp"

#include <stdexcept>

void PushBackToIntArray(int*& array, unsigned int& size, unsigned int& capacity, int value){
    if(size > capacity){
        throw std::invalid_argument("Size cannot be greater than capacity");
    }

    if(array == nullptr){
        capacity = 1;
        size = 1;
        array = new int[capacity];
        array[0] = value;
        return;
    }

    if(size < capacity){
        size += 1;
        array[size - 1] = value;
    } else if(size == capacity) {
        capacity *= 2;
        int *tmp = new int[capacity];
        for(unsigned int i = 0; i < size; i++){
            tmp[i] = array[i];
        }
        tmp[size] = value;
        size += 1;
        delete[] array;
        array = tmp;
    } 
}