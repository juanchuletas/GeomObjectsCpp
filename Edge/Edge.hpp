#ifndef _EDGE_H_
#define _EDGE_H_
//#include "../Node/Node.cpp"
template<class T, int N> class Edge{

    T edgeNode[N];
    public:
        Edge();
        Edge(const T&, const T&);
        T & operator()(int);
        //Setters and Getters
        void setA(const T&);
        void setB(const T&);
        //Getters
        T getA() const;
        T getB() const;
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