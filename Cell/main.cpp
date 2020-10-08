#include <iostream>
#include "Cell.cpp"

int main ()
{
    typedef Vector<double, 2> POINT2D;
    typedef Node<POINT2D> NODE2D;
    typedef Cell<POINT2D,3> triangle;
    POINT2D p1,p2,p3,p4;
    p1.set(0,1.0);
    p1.set(1,1.0);
    p2.set(0,3.0);
    p2.set(1,1.0);
    p3.set(0,1.5);
    p3.set(1,2.5);
    p4.set(0,3.3);
    p4.set(1,2.2);
    NODE2D n1(p1),n2(p2),n3(p3),n4{p4};
    std::cout<<"Target Node 1 adress: "<<&n1<<std::endl;
    std::cout<<"Target Node 2 adress: "<<&n2<<std::endl;
    std::cout<<"Target Node 3 adress: "<<&n3<<std::endl;
    triangle t1{n1,n2,n3},t3;
    triangle t2{t1(0),t1(1),n4};
    //flag = t2.hasNode(n1);
    std::cout<<"Number of sahring cells for node1 in triangle 1 = "<<t1(0).getSharingCells()<<std::endl;
    std::cout<<"Number of sahring cells for node1 in triangle 2 = "<<t2(2).getSharingCells()<<std::endl;
    std::cout<<"But Your Cell contains the node "<<&t1[0]<<std::endl;
    if(t2.hasNode(t1[0])!=0)
    {
        std::cout<<"Match\n";
    }
    
    print(t1); 

    if(t1.shareEdge(t2)!=0)
    {
        std::cout<<"Share edges\n";
    }
    else{
        std::cout<<"They don't\n";
    }
    POINT2D a{0.0,0.0},b{4.0,0.0},c{2.0,3.0},d{4.0,1.0};
    NODE2D v1{a},v2{b},v3{c},point1{d};
    triangle big_t{v1,v2,v3},second{t1};
    bool flag = big_t.contains(v1);


    return 0;
   
}
    // This is the maun function    