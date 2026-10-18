/*
================================================================================
PROBLEM 03: Constructor Overloading (Harry's Lecture 31)
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate constructor overloading by defining multiple constructors in a 
single class that handle different initialization scenarios:
1. Zero arguments (default state: origin / zero).
2. One argument (e.g., setting real part, default imaginary to 0).
3. Two arguments (setting both real and imaginary parts explicitly).

REQUIREMENTS:
1. Class Name: 'Complex'
2. Private Data Members:
   - int a, b; // Represents a + bi
3. Public Constructors:
   - Complex();             // Initializes a = 0, b = 0
   - Complex(int x);        // Initializes a = x, b = 0
   - Complex(int x, int y); // Initializes a = x, b = y
4. Public Member Function:
   - void printNumber();    // Prints "Number: a + bi"
5. In main():
   - Create c1 using default constructor: Complex c1;
   - Create c2 using single parameter:    Complex c2(5);
   - Create c3 using two parameters:       Complex c3(4, 6);
   - Print all three to verify matching initializations.
================================================================================
*/

#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex();
    Complex(int p, int q);
    Complex(int p);
    void printNumber();
};

Complex::Complex()
{
    a = 0;
    b = 0;
}

Complex::Complex(int p, int q)
{
    a = p;
    b = q;
}

Complex::Complex(int p)
{
    a = p;
    b = 0;
}

void Complex::printNumber()
{
    cout << "Your number is " << a << " + " << b << "i" << endl;
}

int main()
{
    Complex c1(4, 6);
    c1.printNumber();

    Complex c2(5);
    c2.printNumber();

    Complex c3;
    c3.printNumber();
    return 0;
}
