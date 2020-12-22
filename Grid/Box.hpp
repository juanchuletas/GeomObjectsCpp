#ifndef _BOX_H_
#define _BOX_H_
#include <vector>
//#include "../Vector/vector.cpp"
template<class T,class V> class Box{
    
    
    std::vector<std::shared_ptr<T>> edges;
    public:
        Box(); 
        void insertElement(std::shared_ptr<T> &);
        std::shared_ptr<T> searchInBox();
        void searchInBox(V&);
        ~Box();

};
#endif
