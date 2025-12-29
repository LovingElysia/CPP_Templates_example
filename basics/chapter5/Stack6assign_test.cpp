#include <iostream>
#include <cassert>
#include "Stack6assign.hpp"

int main(){
    // 基本操作测试（int）
    Stack<int> s;
    assert(s.empty());
    s.Push(1);
    s.Push(2);
    std::cout << "Top after pushes: " << s.Top() << "\n"; // expect 2
    s.Pop();
    assert(s.Top() == 1);

    Stack<int> s2(s); // copy ctor
    assert(!s2.empty());
    s2.Pop();
    assert(s2.empty());

    // 不同类型赋值测试（long -> int）
    Stack<long> sl;
    sl.Push(100L);
    sl.Push(200L);

    Stack<int> si;
    si = sl; // 使用模板赋值运算符
    assert(si.Top() == 200);
    si.Pop();
    assert(si.Top() == 100);

    std::cout << "All tests passed\n";
    return 0;
}
