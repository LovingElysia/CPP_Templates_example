#include<array>
#include<assert.h>

template<typename T,auto MaxSize>
class Stack{
public:
    using Size_type = decltype(MaxSize);
private:
    std::array<T,MaxSize> elems;
    Size_type nums;
public:
    Stack();
    void Push(T elem);
    T Top() const;
    void Pop();  
    bool Empty() const;
    Size_type Size() const {
        return nums;
    }
};

template<typename T,auto MaxSize>
Stack<T,MaxSize>::Stack():nums(0){}

template<typename T,auto MaxSize>
void Stack<T,MaxSize>::Push(T elem){
    assert(nums<MaxSize);
    elems[nums] = elem;
    ++nums;
}

template<typename T,auto MaxSize>
T Stack<T,MaxSize>::Top() const{
    assert(!Empty());
    return elems[nums-1];
}

template<typename T,auto MaxSize>
void Stack<T,MaxSize>::Pop(){
    assert(!Empty());
    --nums;
}


template<typename T,auto MaxSize>
bool Stack<T,MaxSize>::Empty() const{
    return nums == 0;
}

