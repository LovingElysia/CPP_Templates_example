#include<iostream>

template<typename T>
void print(T arg){
    std::cout<<arg<<" ";
} 

template<typename T,typename ... types>
void print(T firstArg,types ... args){
    std::cout<<firstArg<<" ";
    print(args...);
}