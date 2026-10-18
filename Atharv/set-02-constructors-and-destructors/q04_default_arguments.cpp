/*
================================================================================
PROBLEM 04: Constructors with Default Arguments
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate how a single constructor can accept variable numbers of arguments
by assigning default values to parameters from right to left.

REQUIREMENTS:
1. Class Name: 'Simple'
2. Private Data Members:
   - int data1, data2, data3;
3. Public Constructor:
   - Simple(int a, int b = 9, int c = 8);
     Assigns data1 = a, data2 = b, data3 = c.
4. Public Member Function:
   - void printData(); // Prints: "The data is: data1, data2 and data3"
5. In main():
   - Create s1 passing 1 argument:  Simple s1(1);          // uses b=9, c=8
   - Create s2 passing 2 arguments: Simple s2(1, 4);       // uses c=8
   - Create s3 passing 3 arguments: Simple s3(1, 4, 7);    // overrides all defaults
   - Print all three to verify the default argument substitutions.
================================================================================
*/

#include <iostream>
using namespace std;

class Simple
{
    int data1, data2, data3;

public:
    Simple(int a, int b = 9, int c = 8);
    void printdata();
};

Simple::Simple(int a, int b , int c)
{
    data1 = a;
    data2 = b;
    data3 = c;
}
void Simple::printdata()
{
    cout << "The value of data1, data2 and data3 is " << data1 << ", " << data2 << " and " << data3 << endl;
}

int main()
{
    Simple s1(1);
    Simple s2(1, 4);
    Simple s3(1, 4, 7);

    s1.printdata();
    s2.printdata();
    s3.printdata();

    return 0;
}
