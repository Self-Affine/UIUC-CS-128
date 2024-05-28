#include <stdexcept>

#include "person.hpp"
#include "utilities.hpp"

const Person& FindPersonById(const std::vector<Person>& people, unsigned int id){
    for(const Person &person: people){
        if(person.id == id){
            return person;
        }
    }
    throw std::runtime_error("Invalid id number");
}