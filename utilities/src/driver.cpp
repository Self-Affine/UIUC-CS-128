#include <iostream>
#include <string>
#include <map>
 
#include "utilities.hpp"
 
int main() {
    std::string phrase = "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity, it was the season of light, it was the season of darkness, it was the spring of hope, it was the winter of despair.";
    
    // std::vector<std::string> v = WordsToVector(phrase);
    std::map<std::string, unsigned int> result = WordFrequencyCounter(phrase);
    for (auto const& [key, value] : result) { 
        std::cout << key    << ':'    << value    << std::endl;
    }
}