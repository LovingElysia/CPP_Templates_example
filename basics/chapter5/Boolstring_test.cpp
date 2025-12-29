#include <iostream>
#include <cassert>
#include <string>
#include "Boolstring.hpp"

int main(){
    std::string t1 = "true";
    std::string t2 = "false";
    std::string t3 = "on";
    std::string t4 = "1";
    std::string t5 = "no";

    BoolString b1(t1);
    BoolString b2(t2);
    BoolString b3(t3);
    BoolString b4(t4);
    BoolString b5(t5);

    // bool specialization
    assert(b1.get<bool>() == true);
    assert(b2.get<bool>() == false);
    assert(b3.get<bool>() == true);
    assert(b4.get<bool>() == true);
    assert(b5.get<bool>() == false);

    // string retrieval
    auto s = b1.get<std::string>();
    assert(s == "true");

    std::cout << "BoolString tests passed\n";
    return 0;
}
