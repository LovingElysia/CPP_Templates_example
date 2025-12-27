#include "Stack3.hpp"
#include <iostream>
#include <deque>

int main()
{
    Stack<int> intstack;

    Stack<double,std::deque<double>> dbstack;
    intstack.Push(7);
    std::cout<<intstack.Top()<<std::endl;
    intstack.Pop();

    dbstack.Push(3.14);
    std::cout<<dbstack.Top()<<std::endl;
    dbstack.Pop();

    return 0;
}