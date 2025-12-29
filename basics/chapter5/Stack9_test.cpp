#include <iostream>
#include <cassert>
#include "Stack9.hpp"
#include <vector>

int main(){
    // 默认容器 std::deque
    Stack<int> s;
    assert(s.empty());
    s.Push(11);
    s.Push(22);
    std::cout << "Top (deque): " << s.Top() << "\n"; // expect 22
    s.Pop();
    assert(s.Top() == 11);

    // 使用 std::vector 作为底层容器（模板模板参数需要两个参数）
    Stack<int, std::vector> sv;
    assert(sv.empty());
    sv.Push(3);
    sv.Push(4);
    std::cout << "Top (vector): " << sv.Top() << "\n"; // expect 4
    sv.Pop();
    assert(sv.Top() == 3);

    // 不同类型/容器间赋值（long, vector -> int, deque）
    Stack<long, std::vector> slv;
    slv.Push(100L);
    slv.Push(200L);

    s = slv; // 使用模板赋值
    assert(s.Top() == 200);
    s.Pop();
    assert(s.Top() == 100);

    // 交叉容器赋值（deque <- vector）
    Stack<int, std::vector> sv2;
    sv2.Push(7);
    sv2.Push(8);
    Stack<int> s3;
    s3 = sv2;
    assert(s3.Top() == 8);

    std::cout << "Stack9 tests passed\n";
    return 0;
}
