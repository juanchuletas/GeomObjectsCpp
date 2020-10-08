#include<iostream>
#include "Mesh.cpp"
#include "../Edge/Edge.hpp"


int main()
{
  
    typedef Vector<double, 2> POINT2D;
    typedef Node<POINT2D> NODE2D;
    typedef Cell<POINT2D,3> triangle;
    POINT2D a{0.0,0.0}, b{2.0,0.0},c{1.0,1.0},d{2.0,1.0},e{1.0,0.5};

    NODE2D n1{a},n2{b},n3{c},n4{d},n5{e};
    triangle t1{n1,n2,n3},t2{t1(2),t1(1),n4},t3{t2(0),t2(2),n5};

    Mesh<triangle,POINT2D> myMesh{t1};
    myMesh.append(t2);
    //myMesh.append(t3);

    //print(myMesh);
    myMesh.indexing();
    print(myMesh);

    Edge<NODE2D,2> e1{t1(1),t2(2)};

    print(e1(0));
    print(t1((1))); 

    triangle *myT = new triangle;
    myT = myMesh.findContainingCell(n5);
    if(myT!=nullptr)
    {
        std::cout<<"MATCH! THE POINT IS INSIDE THE TRIANGLE:\n";
        print(*myT);
    }
    else{
        std::cout<<"SORRY, MAYBE THE POINT IS AT THE EDGE OR IS A VERTEX\n";
    }
    std::cout<<"FINISH \n";
    t1.~triangle();
    t2.~triangle();
    myT->~triangle();


    return 0;
}