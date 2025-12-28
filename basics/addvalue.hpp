template<int val=5,typename T>
T addvalue(T x){
    return x+val;
}

template<typename T,T val = T{}>
T addvalue(T x){
    return x+val;
}
