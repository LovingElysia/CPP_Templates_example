#include<iostream>

void print(){

}  //用于参数包为空时停止递归

template<typename T,typename ... types>
void print(T firstArg,types ... args){
    std::cout<<firstArg<<" ";
    print(args...);
}