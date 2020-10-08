#include <iostream>
#include "Node.cpp"


int main()
{
    typedef Vector<double,2> POINT2D;
    POINT2D p2;
    p2.set(0,1.0);
    p2.set(1,3.0);
    print(p2);
    //Node<POINT2D> myNode(p2,1,1);
    Node<POINT2D> myNode(p2);
    //myNode.setIndex(0);
    //myNode.increaseSharingCells();
    std::cout<<"The node: "<<myNode.getIndex()<<" with number of sharing cells: "<<myNode.getSharingCells()<<" has the location: \n";
    std::cout<<myNode.decreaseSharingCells()<<std::endl;
    std::cout<<"The node: "<<myNode.getIndex()<<" with number of sharing cells: "<<myNode.getSharingCells()<<" has the location: \n";
    std::cout<<myNode.decreaseSharingCells()<<std::endl;
    std::cout<<"The node: "<<myNode.getIndex()<<" with number of sharing cells: "<<myNode.getSharingCells()<<" has the location: \n";

    //myNode.print();
    myNode.printNode();
    print(myNode);
    return 0;
} 