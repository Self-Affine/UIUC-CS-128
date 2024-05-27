#include "utilities.hpp"

#include <cctype>

std::vector<std::string> WordsToVector(std::string str){
    const std::string PUNCTUATION {"!?.,"};
    std::string noPunctuation {RemoveCharacters(str, PUNCTUATION)};
    return Split(noPunctuation, ' ');
}

std::map<std::string,unsigned int> WordFrequencyCounter(std::string str){

    //remove occurences of ['!', '?', '.', ',']
    str = RemoveCharacters(str, "?!.,");
    //convert str to lower case
    toLowerCase(str);
    //split string based on whitespace
    std::vector<std::string> words {Split(str, ' ')};
    //create map of frequency of case insensitive words
    return createFrequencyMap(words);
}

std::string RemoveCharacters(const std::string &input, const std::string &charactersToRemove){
    std::string tmp {};
    for(char c: input){
        bool keepChar = true;
        for(char remove: charactersToRemove){
            if(c == remove){
                keepChar = false;
                break;
            }
        }
        if(keepChar){
            tmp.push_back(c);
        }
    }
    return tmp;
}

std::vector<std::string> Split(const std::string &input, char splitChar){
    std::vector<std::string> tmp {};
    std::string currentWord {};
    for(char c: input){
        if(c == splitChar){
            if(currentWord.size() > 0){
                tmp.push_back(currentWord);
                currentWord.clear();
            }
        } else {
            currentWord.push_back(c);
        }
    }

    //Push back final word
    if(currentWord.size() > 0){
        tmp.push_back(currentWord);
    }
    return tmp;
}

void toLowerCase(std::string &input){
    for(char &c: input){
        c = tolower(c);
    }
}

std::map<std::string,unsigned int> createFrequencyMap(const std::vector<std::string> &words){
    std::map<std::string,unsigned int> tmp {};
    for(const std::string &word: words){
        if(tmp.contains(word)){
            tmp.at(word) += 1;
        } else {
            tmp.insert({word, 1});
        }
    }
    return tmp;
}