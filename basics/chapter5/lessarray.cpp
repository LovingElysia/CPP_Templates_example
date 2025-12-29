#include "lessarray.hpp"
#include <iostream>

int main(){
    int a1[] = {1,2,3};
    int a2[] = {1,2,3,4};
    std::cout<<less(a1,a2)<<std::endl;

    std::cout<<less("123","1234")<<std::endl;

    return 0;
}