#include <cassert>

#include "number_utilities.hpp"

int main() {
    assert(NumberOddDigitsInInt(111) == 3);
    assert(NumberOddDigitsInInt(-111) == 3);
    assert(NumberOddDigitsInInt(5) == 1);
    assert(NumberOddDigitsInInt(0) == 0);
    assert(NumberOddDigitsInInt(24) == 0);
    assert(NumberOddDigitsInInt(-4) == 0);
    assert(NumberOddDigitsInInt(7546281) == 3);
    assert(NumberOddDigitsInInt(-673402) == 2);
    //std::cout << NoOddDigitsInInt(111) << std::endl;
}