#ifndef _CELL_H_
#define _CELL_H_
#include "../Node/Node.cpp"
template<class T, int N> class Cell{

    Node<T> *vertex[N];
    int index;
    //the first ddata field "vertex" is an array of N pointers to nodes 
    //to point to the N vertices
    //
    public: 
        Cell();
        Cell(Node<T>&a,Node<T>&b,Node<T>&c);
        Cell(Node<T>&, Node<T>&,Node<T>&,Node<T>&);
        //Copy Constructor
        Cell(Cell<T,N>&);
        ~Cell();
        //Assignment Operator
        const Cell& operator=(Cell<T,N>& );
        //int operator<(const Node<T>&, const Cell<T,N>&);
    //Operators
        Node<T>& operator()(int);
        //Set nodes
    //void setNode(Node<T>&, Node<T>&, Node<T>&);
    //Setters and Getters
        int hasNode(const Node<T>&);
        void setIndex(int);
        void resetIndices();
        void indexing(int&);
        int getIndex()const;
        bool contains(const Node<T>&);
        //void print();
        int shareEdge(const Cell<T,N>&);
        const Node<T>& operator[](int i)const {
        return *(vertex[i]);
        }    

};
#endif