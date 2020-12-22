#include<iostream>
using namespace std;
class Test { 
    // private variables 
    int x, y; 
  
public: 
    // dummy constructor 
    Test() {cout<<"HELLO\n";} 
  
    // parameterised constructor 
  
    Test(int x, int y) 
    {
	std::cout<<"CONS\n"; 
        this->x = x; 
        this->y = y; 
    } 
    ~Test(){std::cout<<"DESTRUCTOR\n";}
  
    // function to print 
    void print() 
    { 
        cout << x << " " << y << endl; 
    } 
}; 
  
int main() 
{ 

    int N = 3;
    // allocating dynamic array 
    // of Size N using new keyword 
    Test* arr = new Test[N]; 
  
    // calling constructor 
    // for each index of array 
    for (int i = 0; i < N; i++) { 
        arr[i] = Test(i, i + 1); 
    } 
  
    // printing contents of array 
    for (int i = 0; i < N; i++) { 
        arr[i].print(); 
    } 
    delete [] arr;
  
    return 0; 
} 
