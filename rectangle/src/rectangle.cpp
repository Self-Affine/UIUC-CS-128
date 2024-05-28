#include "rectangle.hpp"

#include <stdexcept>

Rectangle::Rectangle(double width, double height)
    : width_{width}, height_{height}
{
    if(width_ <= 0 || height <= 0){
        throw std::invalid_argument("Invalid argument");
    }
}

void Rectangle::Width(double w){
    if(w <= 0){
        throw std::invalid_argument("Invalid argument");
    }
    width_ = w;
}

void Rectangle::Height(double h){
    if(h <= 0){
        throw std::invalid_argument("Invalid argument");
    }
    height_ = h;
}