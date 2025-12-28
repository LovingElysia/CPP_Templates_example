#include<iostream>
template<typename T>
class AddSpace;

template<typename T>
std::ostream& operator<<(std::ostream&os,AddSpace<T> const& s);

template<typename T>
class AddSpace{
private:
    T const& _ref;
public:
    AddSpace(T const& ref):_ref(ref){}
    friend std::ostream& operator<< <T>(std::ostream& os,AddSpace<T> const& s);
};

template<typename T>
std::ostream& operator<<(std::ostream&os,AddSpace<T> const& s){
    return os<<s._ref<<" ";
}


template<typename ...types>
void print(types...args){
    (std::cout << ... << AddSpace(args))<<'\n';
}
