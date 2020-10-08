#include<iostream>
//#include "../LinkedList/LinkedList.hpp"
#include"Mesh.hpp"


template<class T,class V>
int Mesh<T,V>::indexing(){
    for(Mesh<T,V> *iter = this; 
        iter; iter=(Mesh<T,V>*)iter->next){
            iter->item.resetIndices();
        }
    int count = 0;
    for(Mesh<T,V>* iter = this; iter; iter = (Mesh<T,V>*)iter->next)
    {
        iter->item.indexing(count );
    }
    return count;
}
template<class T,class V>
void Mesh<T,V>::printMesh(){
    //printL(*this);
}
template<class T, class V>
    T *Mesh<T,V>::findContainingCell(const Node<V> &target){
    bool flag;
    std::cout<<"Search method\n";
    for(Mesh<T,V>* iter = this; iter; iter = (Mesh<T,V>*)iter->next)
        {
            //target_triangle = iter->getItem();
            flag = iter->getItem().contains(target());
            if(flag==true)
            {
                std::cout<<"Got it\n";
                return &iter->getItem();
            }
         //print(iter->operator()());
        }
    return nullptr;
    //return this->operator()();
}