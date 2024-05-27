#ifndef UTILITIES_HPP
#define UTILITIES_HPP
 
#include <string>
#include <vector>
#include <map>
 
std::vector<std::string> WordsToVector(std::string str);
std::map<std::string,unsigned int> WordFrequencyCounter(std::string str);

//helper functions
std::string RemoveCharacters(const std::string &input, const std::string &charactersToRemove);
std::vector<std::string> Split(const std::string &input, char splitChar);
void toLowerCase(std::string &input);
std::map<std::string,unsigned int> createFrequencyMap(const std::vector<std::string> &words);
 
#endif
