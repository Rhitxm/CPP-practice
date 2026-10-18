/*
================================================================================
PROBLEM 01: Default Constructor
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate how a default constructor automatically initializes private data
members without needing an explicit setter function.

REQUIREMENTS:
1. Class Name: 'Complex'
2. Private Data Members:
   - int a; // Real part
   - int b; // Imaginary part
3. Public Members:
   - Complex(); // Default constructor: initializes a = 0, b = 0
                // Prints: "Default Constructor Invoked!"
   - void printNumber(); // Prints formatted output: "Number: a + bi"
4. In main():
   - Create three objects: Complex c1, c2, c3;
   - Call printNumber() on each to verify clean default initialization.
================================================================================
*/

#include <iostream>
using namespace std;

int count = 0;

class complex{
    int a;
    int b;
    


    public:
        complex();
        void display();
};

complex :: complex(){
    :: count++;
    cout<<endl<<"Constructor is called for object "<<:: count<<endl;
    a = 0;
    b = 0;
    display();
    
}

void complex :: display(){
    cout<<a<<" + "<<b<<"i"<<endl;
}

int main(){
    complex c1,c2,c3;
    return 0;
}
