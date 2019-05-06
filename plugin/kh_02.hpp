#ifndef KH_02_HPP
#define KH_02_HPP

#include <functional>
#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#define INT_MAX 2147483647


using namespace std;

template<typename T>
inline auto con_T(T text){
    cout << text << endl;
}


template<typename Func,typename... Args>
inline auto curry(Func func, Args... args){

    return [=]( auto... secondParam){   return func(args..., secondParam...);  };

}

template<typename Func,typename... Args>
inline auto curryBackword(Func func, Args... args){

    return [=]( auto... secondParam){   return func( secondParam..., args... );  };

}


template <typename T, typename enable_if_t<is_pointer<T>::value>* = nullptr>
inline auto con_Iarr(T _arr, int size = INT_MAX , int acc = 0){

    if(acc == size || *(_arr + acc) == INT_MAX){ return;}
    cout << *(_arr + acc) << endl;

    return con_Iarr(_arr, size, acc + 1);

}


template <typename T, typename enable_if_t<is_same<T, int(*)[6]>::value>* = nullptr>
inline auto uPai6_pai6( T _pai6, int row = 3 ){


    std::unique_ptr<int*, std::function<void(int**)>> uPtr(new int*[row](),
        [](int** x) {std::for_each(x, x + 3, std::default_delete<int[]>());
                     delete[] x;});

    for(size_t i = 0 ; i < row ; i++){
        uPtr.get()[i] = new int[6];
    }

    for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < 6 ; ++j){
            uPtr.get()[i][j] = _pai6[i][j];
        }
    }


    delete[] _pai6;
    return uPtr;

}

template < typename T , typename Fuc, typename enable_if_t<is_class<T>::value>* = nullptr>
inline auto map_uPai6( T& _uPai6, Fuc _fuc, int row = 3){

    for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < 6 ; ++j){
           _fuc(_uPai6.get()[i][j]);
        }
    }
}
template < typename T , typename Fuc, typename enable_if_t<is_pointer<T>::value>* = nullptr>
inline auto map_Pai6( T& _uPai6, Fuc _fuc, int row = 3){

    for(int i = 0 ; i < row ; ++i){
        for(int j = 0 ; j < 6 ; ++j){
           _fuc(_uPai6[i][j]);
        }
    }
}












///////////자료구조 //////////////////////

//linked list
namespace list {

    struct node{
        int val;
        node* next = nullptr;
    };
    bool push(node* _node, int _val){
        _node->next = new node();
        _node->next->val =_val;
        _node->next->next = nullptr;
        return true;
    }
    int pop_back(node* _list){
        if(_list->next != nullptr)
            pop_back(_list->next);
        else{
            return _list->val;
        }
    }
    void co_nodes(node* _node){
            cout << _node->val << endl;
            if(_node->next != nullptr)
                co_nodes(_node->next);
    }

}
//end linked list





#endif // KH_02_HPP
