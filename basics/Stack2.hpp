#include "Stack1.hpp"
#include <string>
#include <deque>
#include <cassert>

template <>
class Stack<std::string>{
private:
    std::deque<std::string> elems;
public:
    Stack() = default;
    Stack(Stack const& other);
    Stack& operator=(Stack const& other);
    ~Stack() = default;
    void Push(std::string const&);
    std::string const& Top()const;
    void Pop();
    bool Empty() const;
    friend std::ostream& operator<<(std::ostream&os,Stack<std::string> const& stack);
};

void Stack<std::string>::Push(std::string const& elem){
    elems.emplace_back(elem);
}

std::string const& Stack<std::string>::Top() const{
    assert(!elems.empty());
    return elems.back();
}

void Stack<std::string>::Pop(){
    assert(!elems.empty());
    elems.pop_back();
}

bool Stack<std::string>::Empty() const{
    return elems.empty();
}

Stack<std::string>::Stack(Stack const& other):elems(other.elems){}


Stack<std::string>& Stack<std::string>::operator=(Stack const& other){
    elems = other.elems;
    return *this;
}