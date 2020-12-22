 #include "Box.hpp"
#include <iostream>

template<class T,class V>
Box<T,V>::Box(){


    std::cout<<"Hello There\n";
}
template<class T,class V>
void Box<T,V>::insertElement(std::shared_ptr<T> &data)
{
    edges.push_back(data);
}
template<class T, class V>
void Box<T,V>::searchInBox(V &){

// for(auto &iter )


}
template<class T,class V>
Box<T,V>::~Box(){
    std::cout<<"Fuck\n";
}