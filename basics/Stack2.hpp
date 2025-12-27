#include "Stack1.hpp"
#include <string>
#include <deque>
#include <cassert>

template <>
class Stack<std::string>{
private:
    std::deque<std::string> elems;
public:
    void Push(std::string const&);
    std::string const& Top()const;
    void Pop();
    bool Empty() const;
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