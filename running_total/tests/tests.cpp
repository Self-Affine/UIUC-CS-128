#include <catch2/catch_test_macros.hpp>

#include "../src/running_total.hpp"

TEST_CASE("Activity prompt test", "[prompt]"){
    RunningTotal rt;
    rt.Add(10);
    rt.Subtract(1);
    rt.Add(5);
    REQUIRE(rt.History() == "0+10-1+5");
}
