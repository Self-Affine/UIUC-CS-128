#include "military_time.hpp"

#include <stdexcept>
#include <cmath>

std::string ToMilitaryTime(double hours){
    if(hours < 0 || hours > 24.0){
        throw std::invalid_argument("Invalid argument");
    }
    unsigned int hoursInt = static_cast<unsigned int>(hours);
    double minutesDouble = (hours - hoursInt) * 60.0;
    unsigned int minutesInt = static_cast<unsigned int>(round(minutesDouble));

    hoursInt = hoursInt % 24;
    return getFormattedTime(hoursInt, minutesInt);
}

std::string ToMilitaryTime(unsigned int minutes){
    if(minutes > 1440){
        throw std::invalid_argument("Invalid argument");
    }
    unsigned int hours = minutes / 60;
    unsigned int leftOverMinutes = minutes - hours * 60;
    hours = hours % 24;
    return getFormattedTime(hours, leftOverMinutes);
}

std::string getFormattedTime(unsigned int hours, unsigned int minutes){
    std::string hoursString {};
    if(hours < 10){
        hoursString += "0";
    }
    hoursString += std::to_string(hours);

    std::string minutesString {};
    if(minutes < 10){
        minutesString += "0";
    }
    minutesString += std::to_string(minutes);
    return hoursString + ":" + minutesString;
}