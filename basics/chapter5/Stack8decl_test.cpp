#include <iostream>
#include <cassert>
#include "Stack8decl.hpp"
#include <vector>

int main(){
    // 默认容器 std::deque
    Stack<int> s;
    assert(s.empty());
    s.Push(5);
    s.Push(10);
    std::cout << "Top (deque): " << s.Top() << "\n"; // expect 10
    s.Pop();
    assert(s.Top() == 5);

    // 使用 std::vector 作为底层容器（模板模板参数）
    Stack<int, std::vector> sv;
    assert(sv.empty());
    sv.Push(1);
    sv.Push(2);
    std::cout << "Top (vector): " << sv.Top() << "\n"; // expect 2
    sv.Pop();
    assert(sv.Top() == 1);

    // 不同类型/容器间赋值（long, vector -> int, deque）
    Stack<long, std::vector> slv;
    slv.Push(100L);
    slv.Push(200L);

    s = slv; // 使用模板赋值
    assert(s.Top() == 200);
    s.Pop();
    assert(s.Top() == 100);

    std::cout << "Stack8decl tests passed\n";
    return 0;
}
