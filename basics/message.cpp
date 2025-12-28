#include<iostream>

template <auto T>
class Message{
public:
    void print(){
        std::cout<<T<<std::endl;
    }    
};

int main()
{
    Message<42> msg1;
    msg1.print();

    constexpr static char str[] = "hello,world\0"; 
    Message<str> msg2;
    msg2.print();
    
    return 0;
}