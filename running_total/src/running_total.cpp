#include "running_total.hpp"

void RunningTotal::Add(int value){
    total_ += value;
    history_.push_back({.operation = '+', .value = value});
    return;
}

void RunningTotal::Subtract(int value){
    total_ -= value;
    history_.push_back({.operation = '-', .value = value});
    return;
}

std::string RunningTotal::History(){
    std::string tmp {"0"};
    for(const RunningTotalHistoryEntry &entry: history_){
        tmp += entry.operation + std::to_string(entry.value);
    }
    return tmp;
}