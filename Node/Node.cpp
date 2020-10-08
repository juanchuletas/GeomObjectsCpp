#include "Node.hpp"
#include "../Vector/vector.cpp"
#include <iostream>


//Constructors
template<class T>
Node<T>::Node(){
    location = 0;
    index = -1;
    sharingCells = 0;
        //Default constructor.
}
template<class T>
Node<T>::Node(const T& _location)
    :location{_location}{
        index = -1;
        sharingCells = 0;
    }
template<class T>
Node<T>::Node(const T& _location, int _index, int _sharing)
    : location{_location}, index{_index}, sharingCells{_sharing}{
        //With this constructor, the user can write commnands like
        //Node<Point> p; to construct the isolated node at (0,0);
    }
//Copy Constructor
template<class T>
Node<T>::Node(const Node<T>& _node)
    :location{_node.location},index{_node.index},sharingCells{_node.sharingCells}
    {
        std::cout<<"Node Copy constructor called\n"; 
        //std::cout<<"Target Node adress at copy constructor: "<<&_node<<std::endl;  
    }
//Destructor:
template<class T>
Node<T>::~Node(){
    std::cout<<"Node Destructor Called\n";
    //Since there are no pointer fields, the block of the destructor remains empty.
}
//Reading operator
template<class T>
const T& Node<T>::operator()() const{
    return location;
}
//Setters
template<class T>
void Node<T>::setIndex(int _index)
{
    index = _index;
}
//Getters
template<class T>
int Node<T>::getIndex() const{
    return index;
}
//Sharing Cell member functions
template<class T>
int Node<T>::getSharingCells() const{
    return sharingCells;
    //Gives the number of cells that share this node
}
template<class T>
void Node<T>::increaseSharingCells(){
    sharingCells++;
    //increase the number of cells that share this node
}
//Decrease the number od cells that share this node
template<class T>
int Node<T>::decreaseSharingCells(){
    return sharingCells ? !(--sharingCells) : 1;
    //This function decreases the "sharing Cells" field by one.
    // It also returns a 0 so long as the node still serves as a
    // vertex in at least one cell, and 1 once it becomes an isolated node
    //shared by no cel.
}
template<class T>
int Node<T>::noSharingCell() const{
    return !sharingCells;
    //returns a non zero value if and only if "sharingCells" vanishes
}
//Asigment operator
template<class T>
const Node<T>& Node<T>::operator=(const Node& _node){
    if(this!=&_node){
        location = _node.location;
        index = _node.index;
        sharingCells = _node.sharingCells;
    }
    return *this;
}

//Print the nodes
template<class T>
void Node<T>::printNode(){
    //print(node());
    std::cout<<"Node index: "<<index<<"  Sharing Cells: "<<sharingCells<<std::endl;
    std::cout<<"Location: ";
    print(location);
}
template<class T>
void print(const Node<T> & n1)
{
    std::cout<<"Node index: "<<n1.getIndex()<<"  Sharing Cells: "<<n1.getSharingCells()<<std::endl;
    std::cout<<"Location: ";
    print(n1());
}