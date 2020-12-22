#include<iostream>
#include "Mesh.cpp"
#include "../Edge/Edge.hpp"
#include "../Grid/Grid.cpp"
    typedef Vector<double, 2> POINT2D;
    typedef Node<POINT2D> NODE2D;
    typedef Cell<POINT2D,3> triangle;
    typedef Edge<NODE2D,2> EDGE;

void insert(std::vector<std::shared_ptr<EDGE>> &vec, std::shared_ptr<EDGE> &edge){

    std::shared_ptr<EDGE> temPtr = edge;

    vec.push_back(temPtr);

    //double x = edge->operator()(0)()[0]; //Gets the x value of the first node in edge
    //std::cout<<"Edge point a.x value = "<<x<<std::endl;
}

int main()
{
    int xmin = 0, ymin = 0, xmax = 3, ymax = 3;
    int ndivx=3,ndivy=3;
    const int SIZE = ndivx*ndivy;
   
    POINT2D a{0.0,0.0}, b{2.0,0.0},c{1.0,1.0},d{2.0,1.0},e{1.0,0.5};

    NODE2D n1{a},n2{b},n3{c},n4{d},n5{e},p1{{0.5,0.5}},p2{{1.8,1.3}};
    triangle t1{n1,n2,n3}; 
    triangle t2{t1(2),t1(1),n4}; 
    triangle t3{t2(0),t2(2),n5};
    Edge<NODE2D, 2> e1{n1,n3}; 
    std::vector<std::shared_ptr<EDGE>> vec_edges, vect_2;
    std::shared_ptr<EDGE> e2 = std::make_shared<EDGE>(p1,p2);
    std::shared_ptr<EDGE> e3 = std::make_shared<EDGE>(n3,n1);
    int ub = e1.getUbication(n1);
    printf("%d\n",ub);
    //vect_2.push_back(e2);




    /*insert(vec_edges,e2);
    insert(vec_edges,e3);
    for(const auto &iter: vec_edges){
        std::cout<<"HELLO \n";
        std::cout<<"Use count: "<<iter.use_count()<<std::endl;
        print(iter->operator()(0)); 
    }      */



    Grid<EDGE,POINT2D> grid(xmin,xmax,ymin,ymax,ndivx,SIZE);
    grid.insertItem(e2);
    
    
    
    
     //double x = e2->operator()(0)()[0]; //Gets the x value of the first node in edge
    //std::cout<<"Edge point a.x value = "<<x<<std::endl;
    //print(n1);
    Mesh<triangle,POINT2D> myMesh{t1};
    myMesh.append(t2);
    //myMesh.append(t3);

    //print(myMesh);
    myMesh.indexing();
    print(myMesh);

    //Edge<NODE2D,2> e1{t1(1),t2(2)};

    //print(e1(0));
    //print(t1((1))); 

    triangle *myT = new triangle;
    myT = myMesh.findContainingCell(n5);
    if(myT!=nullptr)
    {
        //If the pointer is not NULL it means that the new point is inside
        //of some triangle found it
        std::cout<<"MATCH! THE POINT IS INSIDE THE TRIANGLE:\n";
        print(*myT);
    }
    else{
        //If the pointer is NULL it means that the point is at the edge of some 
        //triangle
        std::cout<<"SORRY, MAYBE THE POINT IS AT THE EDGE OR IS A VERTEX\n";
    }
    std::cout<<"FINISH \n";
    t1.~triangle();
    t2.~triangle();
    //myT->~triangle();

    
    return 0;
}