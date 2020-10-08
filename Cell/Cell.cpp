#include "Cell.hpp"
#include<memory>
template<class T, int N>
Cell<T,N>::Cell()
    {
        index =-1;
        std::cout<<"Cell Constructor Called"<<std::endl;
        for(int i=0; i<N; i++)
        {
            vertex[i] = new Node<T>;
        }
    }   

//Constructor for a cell with three nodes
template<class T, int N>
Cell<T,N>::Cell(Node<T>&a,Node<T>&b,Node<T>&c)
    :index{-1}
{ 
     std::cout<<"Cell COPY Constructor Called"<<std::endl;
    /*if(a.noSharingCell())
    {
        std::cout<<"Sharing value for node 1:  "<<a.noSharingCell()<<std::endl;
        Node<T> *p[2];
        p[0] = new Node<T> {a};
        vertex[0] = p[0];
        std::cout<<"p adress at Cell constructor: "<<p[0]<<std::endl;
        std::cout<<"vertex adress at Cell constructor: "<<vertex[0]<<std::endl;

    }
    else{
        vertex[0] = &a;
    }*/
    vertex[0] = a.noSharingCell() ? new Node<T>(a) : &a;
    vertex[1] = b.noSharingCell() ? new Node<T>(b) : &b;
    vertex[2] = c.noSharingCell() ? new Node<T>(c) : &c;
    //std::cout<<"Target Node adress at constructor: "<<(vertex+1)<<std::endl;
    for(int i = 0; i<N; i++)
    {
        std::cout<<"Increasing the number of sharing Cells\n";
        vertex[i]->increaseSharingCells();
    }
}

//Constructor for a cell with four nodes
template<class T, int N>
Cell<T, N>::Cell(Node<T>&a,Node<T>&b,Node<T>&c,Node<T>&d)
    :index{-1}
{
    std::cout<<"Four node constructor called\n";
    vertex[0] = a.noSharingCell() ? new Node<T>(a) : &a;
    vertex[1] = b.noSharingCell() ? new Node<T>(b) : &b;
    vertex[2] = c.noSharingCell() ? new Node<T>(c) : &c;
    vertex[3] = d.noSharingCell() ? new Node<T>(d) : &d;
    for(int i = 0; i<N; i++)
    {
        vertex[i]->increaseSharingCells();
    }
}
//The Copy Constructor
template<class T, int N>
Cell<T,N>::Cell(Cell<T,N>&input_cell)
    :index{input_cell.index}
{
    for(int i=0; i<N; i++)
    {
        vertex[i] = input_cell.vertex[i];
        vertex[i]->increaseSharingCells();
    }
}
//Asignment operator
template<class T,int N>
const Cell<T,N> &
Cell<T,N>::operator=(Cell<T,N>& input_cell)
{
    if(this!= &input_cell)
    {
        index = input_cell.index;
        for(int i=0; i<N; i++)
        {
            if(vertex[i]->decreaseSharingCells())
            {
                delete vertex[i];
            }
        }
        for(int i=0; i<N; i++)
        {
            vertex[i] = input_cell.vertex[i];
            vertex[i]->increaseSharingCells();
        }
    }
    return *this;
}
//Reading and Accessing vertices
template<class T, int N>
Node<T>& Cell<T,N>::operator()(int i)
{
    return *(vertex[i]);
}
/*template<class T,int N>
const Node<T>& operator[](int i){
    return *(vertex[i]);

}*/
//read only vertex because of the const type
template<class T, int N>
void Cell<T,N>::setIndex(int i){
    index = i;
}
template<class T, int N>
void Cell<T,N>::resetIndices(){
    for(int i=0; i<N; i++)
        vertex[i]->setIndex(-1);
}
//Indexing 
template<class T, int N>
void Cell<T,N>::indexing(int& count)
{
    for(int i=0; i<N; i++)
    {
        if(vertex[i]->getIndex()<0)
        {
            vertex[i]->setIndex(count++);
        }
    }
}
//Get index
template<class T, int N>
int Cell<T,N>::getIndex() const{
    return index;
}
//Check if the cell contains the node
template<class T, int N>
int Cell<T,N>::hasNode(const Node<T>& node)
{
    for(int i=0; i<N; i++)
    {
        std::cout<<"Target Node adress: "<<&node<<std::endl;
        std::cout<<"Vertex in cell adress: "<<vertex[i]<<std::endl;
        if(&node==this->vertex[i]){
            return i+1;
        }
    }
    return 0;

}
//Print cells
/*template<class T, int N>
void Cell<T,N>::print()
{
    for(int i=0; i<N; i++)
        this->vertex[i]->printNode();
}*/
//Destructor
template<class T, int N>
Cell<T,N>::~Cell(){
    std::cout<<"Cell Destructor called\n";
    for(int i=0; i<N; i++)
    {
        if(vertex[i]->decreaseSharingCells())
        {
            delete vertex[i];
        }
    }
}
template<class T, int N>
int Cell<T,N>::shareEdge(const Cell<T,N>& c1){

    int count=0;
    for(int i=0; i<N; i++)
    {
        if(this->hasNode(c1[i])!=0)
        {
            std::cout<<"Match share edge module\n";
            count++;
        }
    }
    std::cout<<"Count Value: "<<count<<"\n";
    return count;
}
template<class T,int N>
void print(const Cell<T,N>& c1)
{
    for(int i=0; i<N; i++)
        print(c1[i]);
}
template<class T,int N> 
bool Cell<T,N>::contains(const Node<T> &point)
{
    T point_a = this->operator()(0)();
    T point_b = this->operator()(1)();
    T point_c = this->operator()(2)();
    T point_ba = point_b-=point_a;
    T point_ca = point_c-=point_a;
    T point_cb = point_c-=point_b;
    T point_p  = point();
    T point_pa = point_p-=point_a;
    T point_pb = point_p-=point_b;
    double c1,c2,c3;
    c1 = point_ba.perdot(point_pa);
    c2 = point_pa.perdot(point_ca);
    c3 = point_cb.perdot(point_pb);


    if(c1*c2*c3>0)
    {
        std::cout<<"Node inside the Cell\n";

        return true;
    }
    else{
        std::cout<<"Node not inside the Cell or in the edge\n";
        return false;
    }
}