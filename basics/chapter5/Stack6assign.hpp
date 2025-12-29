#include <deque>
#include <cassert>

template<typename T>
class Stack{
private:
    std::deque<T> elems;
public:
    void Push(T elem);
    T Top () const;
    void Pop();
    bool empty()const;
    Stack() = default;
    Stack(Stack const& other);

    template<typename T2>
    Stack& operator=(Stack<T2> const& other);
    //添加所有其他类型的Stack为友元
    template<typename>friend class Stack;
private:
    void clear();
};

template<typename T>
void Stack<T>::Push(T elem){
    elems.emplace_back(elem);
}

template<typename T>
T Stack<T>::Top() const{
    assert(!empty());
    return elems.back();
}

template<typename T>
void Stack<T>::Pop() {
    assert(!empty());
    elems.pop_back();
}

template<typename T>
bool Stack<T>::empty() const{
    return elems.empty();
}

template<typename T>
void Stack<T>::clear(){
    while(!elems.empty())elems.pop_back();
}
template<typename T>
Stack<T>::Stack(Stack<T> const& other):elems{other.elems}{}

template<typename T>
    template<typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& other){

    Stack<T2> tmp(other);
    clear();
    elems.insert(elems.begin(),other.elems.begin(),other.elems.end());
    return *this;
}    