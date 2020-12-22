#ifndef _EDGE_H_
#define _EDGE_H_
//#include "../Node/Node.cpp"
template<class T, int N> class Edge{

    T edgeNode[N];
    public:
        enum ubication {LEFT,RIGHT,FRONT,BEHIND,MIDDLE,ORIGIN,DEST};
        Edge();
        Edge(const T&, const T&);
        ~Edge(){std::cout<<"Edge Desttructor\n";};
        T & operator()(int);
        //Setters and Getters
        void setA(const T&);
        void setB(const T&);
        ubication getUbication(T&);
        //Getters
        T getA() const;
        T getB() const;
        //method

};
template<class T,int N>
Edge<T, N>::Edge(){
    //Default
    std::cout<<"Default constructor";
    for(int i=0; i<N; i++)
        edgeNode[i] = 0;
}
template<class T, int N>
Edge<T, N>::Edge(const T& a_in,const T& b_in)
    {
        std::cout<<"Edge Constructor\n";
        edgeNode[0] = a_in;
        edgeNode[1] = b_in;
    }
template<class T, int N>
T & Edge<T,N>::operator()(int i)
{
    return edgeNode[i];
}
template<class T, int N>
enum Edge<T,N>::ubication Edge<T,N>::getUbication( T& point){
    std::cout<<"get ubication\n";
    double x1 = this->operator()(0)()[0]; //Access to de x coordinate of the first node of the edge
    double y1 = this->operator()(0)()[1];
    double x2 = this->operator()(1)()[0];
    double y2 = this->operator()(1)()[1];
    double a[]={x2-x1,y2-y1};
    double px = point()[0];
    double py = point()[1];
    double b[] = {px-x1,py-y1};
    double amod = sqrt(a[0]*a[0] + a[1]*a[1]);
    double bmod = sqrt(b[0]*b[0] + b[1]*b[1]);

    double sa = a[0]*b[1] - b[0]*a[1];
    if(sa>0.f) return ubication::LEFT;
    else if(sa<0.f) return ubication::RIGHT;
    else if((a[0]*b[0]<0.f) || (a[1]*b[1]<0.f)) return ubication::BEHIND;
    else if(amod<bmod) return ubication::FRONT;
    else if(this->operator()(0)==point) return ubication::ORIGIN;
    else if(point == this->operator()(1)) return ubication::DEST;

    return ubication::MIDDLE;
    //print(this->operator()(0));

}
/*template<class T, int N> 
void Edge<T, N>::setA(const T& a_in)
{
    a = a_in;
}
template<class T,int N> 
void Edge<T, N>::setB(const T&b_in)
{
    b = b_in;
}
template<class T,int N>
T Edge<T, N>::getA() const
{
    print(a);
}
template<class T,int N>
T Edge<T, N>::getB() const
{
   print(b);
}*/
#endif