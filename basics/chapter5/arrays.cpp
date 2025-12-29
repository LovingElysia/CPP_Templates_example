#include"arrays.hpp"

template<typename T1,typename T2,typename T3>
void foo(
    int a1[7],int a2[],                         //根据语法规则划分指针类型
    int (&a3)[42],                              //已知边界数组的引用
    int (&x0)[],                                //未知边界数组的引用
    T1 x1,                                      //值传递类型退化
    T2& x2,T3&& x3                              //引用传递
){
    Myclass<decltype(a1)>::foo();
    Myclass<decltype(a2)>::foo();
    Myclass<decltype(a3)>::foo();
    Myclass<decltype(x0)>::foo();
    Myclass<decltype(x1)>::foo();
    Myclass<decltype(x2)>::foo();
    Myclass<decltype(x3)>::foo();
}

int main()
{
    int a[42];
    Myclass<decltype(a)>::foo();

    extern int x[];
    Myclass<decltype(x)>::foo();

    foo(a,a,a,x,x,x,x);

}

int x[]={1,2,3};