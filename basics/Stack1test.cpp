#include "Stack1.hpp"
#include <iostream>
#include <string>

int main(){
    Stack<int> Intstack;
    Stack<std::string> Strstack;

    //使用int类型的栈
    Intstack.Push(1);
    std::cout<<Intstack.Top()<<std::endl;

    //使用string类型的栈
    Strstack.Push("hello");
    std::cout<<Strstack.Top()<<std::endl;
    Strstack.Pop();

    return 0;
}