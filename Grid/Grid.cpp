#include "Grid.hpp"
#include<iostream>

template<class T,class V>
Grid<T,V>::Grid(int x_i, int x_f,int y_i, int y_f,int ndiv,int size)
    :xmin{x_i},xmax{x_f},ymin{y_i},ymax{y_f},ndivisions{ndiv},SIZE{size}{    
        hx = (xmax-xmin)/(double)ndivisions;
        hy = (ymax-ymin)/(double)ndivisions;
        box_size = hx;

        grid = new Box<T,V>[SIZE];
        for(int i=0; i<SIZE; i++)
        {
            grid[i] = Box<T,V>();
        }     

    }
template<class T,class V>
Box<T,V> Grid<T,V>::getBox(double x, double y){

    double hx = (xmax-xmin)/(double)ndivisions;
    double hy = (ymax-ymin)/(double)ndivisions;

    int i = ((int)(x/hx))%ndivisions;
    int j = ((int)(y/hy))%ndivisions;
    int index = i + j*ndivisions;
    std::cout<<"YOUR POINT IS INSIDE BOX["<<index<<"]\n";
    Box<T,V> box = grid[index];

    return box;
}
template<class T,class V>
void Grid<T,V>::insertItem(std::shared_ptr<T> &data){
double x1 = data->operator()(0)()[0]; //Access to de x coordinate of the first node of the edge
double y1 = data->operator()(0)()[1];
double x2 = data->operator()(1)()[0];
double y2 = data->operator()(1)()[1];
//Define the vector u = edge.b - edge.b;
double u[2];
u[0] = x2-x1; u[1] = y2-y1;
double xstep = (u[0]>=0) ? 1 : -1;
double ystep = (u[1]>=0) ? 1 : -1;


std::cout<<"HELLO FROM INSERT ITEM\n";

//PAssing to integer values
int xint1 = ((int)(x1/hx))%ndivisions;
int yint1 = ((int)(y1/hy))%ndivisions;
int xint2 = ((int)(x2/hx))%ndivisions;
int yint2 = ((int)(y2/hy))%ndivisions;

int currentBox_x = xint1; int currentBox_y = yint1;


double nextBoxBound_x = (currentBox_x + xstep)*box_size;
double nextBoxBound_y = (currentBox_y + ystep)*box_size;

//The value of t
double tMAxVal_x = (u[0]!=0) ? (nextBoxBound_x-x1)/u[0] : __DBL_MAX__;
double tMAxVal_y = (u[1]!=0) ? (nextBoxBound_y-y1)/u[1] : __DBL_MAX__;


double tDeltaX = (u[0]!=0) ? box_size/(u[0]*xstep) : __DBL_MAX__;
double tDeltay = (u[1]!=0) ? box_size/(u[1]*ystep) : __DBL_MAX__;

//Start and the end of the grid in 1D form
int start = (xint1 + yint1*ndivisions);
int end = (xint2 + yint2*ndivisions);
int xfoo = xint1;
int yfoo = yint1;
std::cout<<"BOX("<<xfoo<<", "<<yfoo<<" )"<<std::endl;
while(start!=end){

    if(tMAxVal_x<tMAxVal_y){
        tMAxVal_x = tMAxVal_x + tDeltaX;
        xfoo+=xstep;
        start = (xfoo + yfoo*ndivisions);
    }
    else{
        tMAxVal_y = tMAxVal_y + tDeltay;
        yfoo+=ystep;
        start = (xfoo + yfoo*ndivisions);
        
    }
    std::cout<<"BOX("<<xfoo<<", "<<yfoo<<" )"<<std::endl;
}




}

template<class T,class V>
Grid<T,V>::~Grid(){

delete [] grid;
}