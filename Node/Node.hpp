#ifndef _NODE_H_
#define _NODE_H_
template<class T> class Node{
    T location;
    int index;
    int sharingCells;
    public:
        Node();
        Node(const T&);
        Node(const T&, int, int);
        //Copy Constructor
        Node(const Node<T>&);
        //Destructor
        ~Node();
        //Reading operator
        const T& operator()()const;
        //Setter
        void setIndex(int);
        //Getters
        int getIndex()const;
        //Sharing cells member functions
        int getSharingCells() const;
        void increaseSharingCells();
        int decreaseSharingCells();
        int noSharingCell() const;
        //Asignment operator
        const Node& operator=(const Node&);
        void printNode();
};
#endif