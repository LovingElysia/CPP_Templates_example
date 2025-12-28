#include<iostream>
#include"Stacknotype.hpp"

int main()
{
    Stack<int,20> int20stack;
    Stack<std::string,40> string40stack;

    int20stack.Push(7);
    std::cout<<int20stack.Top()<<std::endl;
    int20stack.Pop();

    string40stack.Push("hello");
    std::cout<<string40stack.Top()<<std::endl;
    string40stack.Pop();

    return 0;
}
