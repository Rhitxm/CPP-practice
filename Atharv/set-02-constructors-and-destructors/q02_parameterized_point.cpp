/*
================================================================================
PROBLEM 02: Parameterized Constructor & 2D Point Distance
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate how parameterized constructors pass arguments during object 
creation using both implicit and explicit syntax, and compute Euclidean distance 
between two Point objects using a friend function.

MATHEMATICAL FORMULA:
Distance between Point P1(x1, y1) and Point P2(x2, y2):
Distance = sqrt((x2 - x1)^2 + (y2 - y1)^2)
Header required for sqrt and pow: #include <cmath>

REQUIREMENTS:
1. Class Name: 'Point'
2. Private Data Members:
   - int x, y;
3. Public Members:
   - Point(int a, int b); // Parameterized constructor assigning x = a, y = b
   - void displayPoint(); // Prints: "Point is (x, y)"
4. Friend Function:
   - friend double calculateDistance(Point p1, Point p2);
     Computes and returns the Euclidean distance as a double.
5. In main():
   - Create Point p1 using Implicit call: Point p1(1, 1);
   - Create Point p2 using Explicit call: Point p2 = Point(4, 5);
   - Display both points.
   - Call calculateDistance(p1, p2) and print the result.
   - Expected distance between (1, 1) and (4, 5): 5.0
================================================================================
*/
