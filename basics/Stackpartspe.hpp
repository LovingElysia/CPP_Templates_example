#include "Stack1.hpp"

template<typename T>
class Stack<T*>{
private:
    std::vector<T*> elems;
public:
    void Push(T* elem);
    T* Top()const;
    void Pop();
    bool Empty() const;
};

template<typename T>
void Stack<T*>::Push(T* elem){
    elems.emplace_back(elem);
}

template<typename T>
void Stack<T*>::Pop(){
    assert(!Empty());
    elems.pop_back();
}

template<typename T>
T* Stack<T*>::Top()const{
    assert(!Empty());
    return elems.back();
}

