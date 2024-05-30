#ifndef RUNNING_TOTAL_HPP
#define RUNNING_TOTAL_HPP

#include "running_total_history_entry.hpp"

#include <vector>
#include <string>

class RunningTotal{
public:
    RunningTotal() : total_{0}{};

    int CurrentTotal() const {return total_;}

    void Add(int value);
    void Subtract(int value);
    std::string History();
private:
    int total_;
    std::vector<RunningTotalHistoryEntry> history_;
};

#endif
