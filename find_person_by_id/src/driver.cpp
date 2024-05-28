#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "person.hpp"
#include "utilities.hpp"

int main() {
    std::vector<Person> people {{"Bob", "A", 1}, {"Charlie", "B", 2}, {"Kathy", "C", 200}};
    assert(FindPersonById(people, 1).first_name == "Bob");
    assert(FindPersonById(people, 200).last_name == "C");
    assert(FindPersonById(people, 2).first_name == "Charlie");
    try{
        FindPersonById(people, 0);
    } catch(const std::runtime_error &e){
        std::cout << "Caught exception";
    }
}