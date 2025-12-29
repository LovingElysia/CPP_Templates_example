#include<deque>
#include<cassert>
#include<memory>

/*在C++17之前 对模板的模板参数必须要完全匹配
所以,这里的问题是,std::deque实际上的模板参数不止一个
*/
template<typename T,template <typename elem> class Cont=std::deque>
class Stack{
private:
    Cont<T> elems;
public:
    void Push(T elem);
    T Top () const;
    void Pop();
    bool empty()const;
    Stack() = default;
    Stack(Stack const& other);

    template<typename T2,template <typename elem> class Cont2>
    Stack& operator=(Stack<T2,Cont2> const& other);
    //添加所有其他类型的Stack为友元
    template<typename, template <typename> class> friend class Stack;
private:
    void clear();
};

template<typename T,template <typename elem> class Cont>
void Stack<T,Cont>::Push(T elem){
    elems.emplace_back(elem);
}

template<typename T,template <typename elem> class Cont>
T Stack<T,Cont>::Top() const{
    assert(!empty());
    return elems.back();
}

template<typename T,template <typename elem> class Cont>
void Stack<T,Cont>::Pop() {
    assert(!empty());
    elems.pop_back();
}

template<typename T,template <typename elem> class Cont>
bool Stack<T,Cont>::empty() const{
    return elems.empty();
}

template<typename T,template <typename elem> class Cont>
void Stack<T,Cont>::clear(){
    while(!elems.empty())elems.pop_back();
}
template<typename T,template <typename elem> class Cont>
Stack<T,Cont>::Stack(Stack<T,Cont> const& other):elems{other.elems}{}

template<typename T,template <typename elem> class Cont>
    template<typename T2,template <typename elem> class Cont2>
Stack<T,Cont>& Stack<T,Cont>::operator=(Stack<T2,Cont2> const& other){

    Stack<T2, Cont2> tmp(other);
    clear();
    elems.insert(elems.begin(),other.elems.begin(),other.elems.end());
    return *this;
}    