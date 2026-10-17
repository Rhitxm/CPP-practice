/*
================================================================================
PROBLEM 07: Swapping Private Data (Friend Function with Call by Reference)
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate how a global friend function can modify the private member variables
of two distinct class instances in-place using reference parameters (&).

REQUIREMENTS:
1. Forward Declaration:
   - Declare 'class ClassB;' before 'class ClassA;'.
2. Class 'ClassA':
   - Private member: int valA;
   - Public methods: void setData(int a), void display()
   - Friend declaration: friend void swapValues(ClassA &x, ClassB &y);
3. Class 'ClassB':
   - Private member: int valB;
   - Public methods: void setData(int b), void display()
   - Friend declaration: friend void swapValues(ClassA &x, ClassB &y);
4. Global Friend Function:
   - void swapValues(ClassA &x, ClassB &y)
     Uses pass-by-reference (&) to swap x.valA and y.valB using a temporary
     variable so changes reflect in the caller's objects.
5. In main():
   - Create one object of each class, set their initial values, display them,
     call swapValues(objA, objB), and display them again to verify the swap.
================================================================================
*/

#include <iostream>
using namespace std;

class B;

class A
{
    int a;
    friend void swap(A &d1, B &d2);

public:
    void setdata(int n);
    void display();
};

class B
{
    int b;
    friend void swap(A &d1, B &d2);

public:
    void setdata(int m);
    void display();
};

void A::setdata(int n)
{
    a = n;
}

void A::display()
{
    cout << "Value of a: " << a << endl;
}

void B::setdata(int m)
{
    b = m;
}

void B::display()
{
    cout << "Value of b: " << b << endl;
}

void swap(A &d1, B &d2)
{
    int temp = d1.a;
    d1.a = d2.b;
    d2.b = temp;
}

int main()
{
    A d1;
    B d2;
    int n, m;

    cout << "Enter value of a: ";
    cin >> n;
    cout << "Enter value of b: ";
    cin >> m;

    d1.setdata(n);
    d2.setdata(m);

    cout << "\n--- Before Swap ---" << endl;
    d1.display();
    d2.display();

    swap(d1, d2);

    cout << "\n--- After Swap ---" << endl;
    d1.display();
    d2.display();

    return 0;
}