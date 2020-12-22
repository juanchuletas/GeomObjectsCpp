#include<iostream>
#include "Grid.cpp"
#include "../Mesh/Mesh.cpp"
#include "../Edge/Edge.hpp"
//#include "Box.cpp"

int main (){

    typedef Vector<double,2> POINT2D;
    int xmin = 0, ymin = 0, xmax = 3, ymax = 3;
    int ndivx=3,ndivy=3;
    const int SIZE = ndivx*ndivy;
    POINT2D p1{1.5,0.5};

    Grid<POINT2D> mygrid(xmin,xmax,ymin,ymax,ndivx,SIZE);
    mygrid.insertItem(p1);  
    /*Box<POINT2D> *array_box = new Box<POINT2D>[SIZE];


    for(int i = 0; i<SIZE; i++)
    {
        array_box[i] = Box<POINT2D>();
    }*/



    //delete[] array_box;

    return 0;
}