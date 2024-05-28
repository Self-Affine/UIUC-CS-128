#ifndef MILITARY_TIME_HPP
#define MILITARY_TIME_HPP

#include <string>

std::string ToMilitaryTime(double hours);

std::string ToMilitaryTime(unsigned int minutes);

std::string getFormattedTime(unsigned int hours, unsigned int minutes);

#endif
