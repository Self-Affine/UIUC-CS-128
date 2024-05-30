#include <iostream>

#include "solution.hpp"
#include "student.hpp"

int main(){
    Student bob {.first_name = "Bob", .last_name = "Roberts", .uin = 1003};

    std::cout << bob;
}