#include "shopping_list.hpp"
#include <vector>
#include <fstream>

std::vector<Item> LoadItemsToVector(std::string fileName) {
    std::vector<Item> items;
    
    std::ifstream ifs {fileName, std::ios_base::in};
    if(!ifs.is_open()){
        throw std::runtime_error("Failed to open file");
    }

    while(ifs.good()){
        Item newItem {};
        ifs >> newItem.itemName >> newItem.quantity >> newItem.price;
        if(ifs.fail()){
            throw std::runtime_error("Invalid file format");
        }
        items.push_back(newItem);
    }

    return items;
    
}