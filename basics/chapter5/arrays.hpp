#include<iostream>

template<typename T>
struct Myclass;

template<typename T,size_t sz>
struct Myclass<T[sz]>    //对已知数组边界信息的偏特化
{
public:
    static void foo(){
        std::cout<<"print() for T["<<sz<<"]\n";
    }
};

template<typename T>
struct Myclass<T[]>   //对未知数组边界信息的偏特化
{
public:
    static void foo(){
        std::cout<<"print() for T["<<"]\n";
    }
};

template<typename T,size_t sz>
struct Myclass<T(&)[sz]>{ //对已知数组边界信息的引用特化
public:
    static void foo(){
        std::cout<<"print() for T(&)["<<sz<<"]\n";
    }
};

template<typename T>
struct Myclass<T(&)[]> //对未知数组边界信息的引用特化
{
public:
    static void foo(){
        std::cout<<"print() for T(&)["<<"]\n";
    }
};

template<typename T>
struct Myclass<T*>  //指针偏特化
{
public:
   static void foo(){
        std::cout<<"print() for T*\n";
    }
};

