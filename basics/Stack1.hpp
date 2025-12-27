#include<vector>
#include<cassert>

template <typename T>
class Stack{
private:
  std::vector<T> elems  ;
public:
  Stack() = default;

  //在只需要类名而非类型名的地方。 请只使用类名
  Stack(Stack const& other);
  Stack& operator=(Stack const& other);
  /* 即使下面的声明与上面使等价的
  Stack(Stack<T> const& other);
  Stack<T>& operator=(Stack<T> const& other);
  */
 ~Stack() = default;
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

template<typename T>
Stack<T>::Stack(Stack const& other){
    elems.emplace_back(other.elems);
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack const& other){
    elems = other.elems;
    return *this;
}
