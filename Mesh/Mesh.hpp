#ifndef _MESH_H_
#define _MESH_H_
#include "../LinkedList/LinkedList.hpp"
//#include "../Edge/Edge.hpp"
template<class T,class V> class Mesh : public LinkedList<T>{

    
    public:

        Mesh(){

        }
        Mesh(T& object){
            this->item = object;
            //Why do we need to use the "this" object with a
            //template class?
        }
    
    //methods

    int indexing();
    void printMesh();
    T *findContainingCell(const Node<V>&);



};

#endif