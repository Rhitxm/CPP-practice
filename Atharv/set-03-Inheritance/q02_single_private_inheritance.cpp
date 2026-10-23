/*
================================================================================
PROBLEM 02: Single Inheritance with Private Visibility (Harry's Lecture 38)
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate how inheriting a base class PRIVATELY alters member visibility,
making base public members private inside the derived class, and how to access
them using derived class member functions.

REQUIREMENTS:
1. Base Class: 'Base'
   - Private Data Member: int data1
   - Public Data Member: int data2
   - Public Member Functions:
     - void setData(int a, int b); // Sets data1 = a, data2 = b
     - int getData1();             // Returns data1
     - int getData2();             // Returns data2

2. Derived Class: 'Derived' (PRIVATELY inherits from 'Base')
   - Private Data Member: int data3
   - Public Member Functions:
     - void process(); // Calls setData(10, 20) internally and computes data3 = data2 * getData1()
     - void display(); // Displays data1, data2, and data3

3. In main():
   - Create 'Derived der;'
   - Note: der.setData(...) CANNOT be called directly in main() because it became private!
   - Call der.process();
   - Call der.display();
================================================================================
*/
