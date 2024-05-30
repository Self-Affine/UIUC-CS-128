#include "solution.hpp"

std::ostream& operator<<(std::ostream &os, const Student &student){
    os << "Name: <" << student.first_name << "> <" << student.last_name << ">" << std::endl;
    os << "UIN: <" << student.uin << ">" << std::endl;
    return os;
}