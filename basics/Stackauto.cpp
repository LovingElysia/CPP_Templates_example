#include<iostream>
#include"Stacknotype.hpp"
#include<type_traits>

int main()
{
    constexpr int size {40};
    constexpr unsigned int size_2{20};
    Stack<int,size_2> int20stack;
    Stack<std::string,size> string40stack;

    int20stack.Push(7);
    std::cout<<int20stack.Top()<<std::endl;
    auto size1 = int20stack.Size();
    int20stack.Pop();

    string40stack.Push("hello");
    std::cout<<string40stack.Top()<<std::endl;
    auto size2 = string40stack.Size();
    string40stack.Pop();

    if(!std::is_same_v<decltype(size1),decltype(size2)>){
        std::cout<<"size type differ"<<std::endl;
    }
    return 0;
}
