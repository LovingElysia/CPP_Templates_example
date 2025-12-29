template <typename T,int N,int M>
bool less(T(&array1)[N],T(&array2)[M]){
    for(int i=0;i<N && i<M ;++i){
        if(array1[i]<array2[i])return true;
        if(array1[i]>array2[i])return false;
    }
    return N<M;
}

template <int N,int M>
bool less(char const(&a)[N],char const(&b)[M]){
        for(int i=0;i<N && i<M ;++i){
        if(a[i]<b[i])return true;
        if(a[i]>b[i])return false;
    }
    return N<M;
}