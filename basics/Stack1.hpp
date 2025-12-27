#include<vector>
#include<cassert>

template <typename T>
class Stack{
private:
  std::vector<T> elems  ;
public:
  void Push(T elem);
  void Pop();
  T const& Top() const;
  bool Empty() const;  
};

template <typename T>
void Stack<T>::Push(T elem){
    elems.emplace_back(elem);
}

template <typename T>
void Stack<T>::Pop(){
    elems.pop_back();
}

template <typename T>
T const& Stack<T>::Top()const{
    assert(!Empty());
    return elems.back();
}