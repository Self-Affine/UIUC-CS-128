#include "utilities.hpp"

bool operator==(const Student &lhs, const Student &rhs){
    return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name && lhs.uin == rhs.uin;
}