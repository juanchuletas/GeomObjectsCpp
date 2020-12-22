#ifndef _GRID_H_
#define _GRID_H_
#include "Box.cpp"
template<class T,class V> class Grid
{

    Box<T,V> *grid;
    int SIZE;
    int xmin,xmax,ymin,ymax;
    int ndivisions;
    double hx, hy;
    double box_size;


    public:

    Grid(int x_i, int x_f,int y_i, int y_f,int ndiv,int size);
    Box<T,V> getBox(double,double);
    void insertItem(std::shared_ptr<T> &);
    //void assignEdgeToGrid();
    ~Grid();


};



#endif