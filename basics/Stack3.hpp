#include<vector>
#include<cassert>
#include<ostream>

template <typename T,typename Cont = std::vector<T>>
class Stack{
private:
  Cont elems  ;
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

//每一个成员函数都必须含有这两个类型参数
template <typename T,typename Cont>
void Stack<T,Cont>::Push(T elem){
    elems.emplace_back(elem);
}


template <typename T,typename Cont>
void Stack<T,Cont>::Pop(){
    assert(!Empty());
    elems.pop_back();
}


template <typename T,typename Cont>
T const& Stack<T,Cont>::Top()const{
    assert(!Empty());
    return elems.back();
}

template <typename T,typename Cont>
Stack<T,Cont>::Stack(Stack const& other):elems(other.elems){}


template <typename T,typename Cont>
Stack<T,Cont>& Stack<T,Cont>::operator=(Stack const& other){
    elems = other.elems;
    return *this;
}


template <typename T,typename Cont>
bool Stack<T,Cont>::Empty() const{
    return elems.empty();
}