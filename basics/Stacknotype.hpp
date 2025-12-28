#include<array>
#include<assert.h>

template<typename T=int,size_t MaxSize=100>
class Stack{
private:
    std::array<T,MaxSize> elems;
    size_t nums;
public:
    Stack();
    void Push(T elem);
    T Top() const;
    void Pop();
    std::size_t Size() const;     
    bool Empty() const;
};

template<typename T,size_t MaxSize>
Stack<T,MaxSize>::Stack():nums(0){}

template<typename T,size_t MaxSize>
void Stack<T,MaxSize>::Push(T elem){
    assert(nums<MaxSize);
    elems[nums] = elem;
    ++nums;
}

template<typename T,size_t MaxSize>
T Stack<T,MaxSize>::Top() const{
    assert(!Empty());
    return elems[nums-1];
}

template<typename T,size_t MaxSize>
void Stack<T,MaxSize>::Pop(){
    assert(!Empty());
    --nums;
}


template<typename T,size_t MaxSize>
bool Stack<T,MaxSize>::Empty() const{
    return nums == 0;
}


template<typename T,size_t MaxSize>
size_t Stack<T,MaxSize>::Size() const{
    return nums;
}