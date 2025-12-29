#include <iostream>
#include <cassert>
#include "Stack5decl.hpp"

int main(){
    Stack<int> s;
    assert(s.empty());

    s.Push(10);
    s.Push(20);
    std::cout << "Top after pushes: " << s.Top() << "\n"; // expect 20

    s.Pop();
    assert(s.Top() == 10);

    Stack<int> s2(s); // copy ctor
    assert(!s2.empty());
    s2.Pop();
    assert(s2.empty());

    Stack<double> sd;
    sd.Push(1.5);
    sd.Push(2.5);
    std::cout << "Double Top: " << sd.Top() << "\n";

    // copy-assignment (same type)
    s2 = s;
    assert(s2.Top() == 10);

    std::cout << "All tests passed\n";
    return 0;
}
