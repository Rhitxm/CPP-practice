/*
================================================================================
PROBLEM 08: The Geometry Engine (Friend Class & Member Friends)
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate how a helper/utility class can be granted friend status to access
and perform geometric computations on the private data of a Shape class.

SCENARIO:
We have two classes:
1. 'Rectangle': Stores the private dimensions of a rectangle (length and width).
2. 'GeometryEngine': A utility class that calculates properties of shapes.
   - float calculateArea(Rectangle r);
   - float calculatePerimeter(Rectangle r);
   - bool isSquare(Rectangle r);

KEY OOP CONSTRAINTS & ORDER OF DECLARATION:
- 'length' and 'width' in 'Rectangle' MUST be private.
- Forward declare 'class Rectangle;' before 'class GeometryEngine;'.
- Declare 'GeometryEngine' first, but only write prototypes for functions that
  take 'Rectangle' as an argument.
- Define 'class Rectangle' and declare 'friend class GeometryEngine;' inside it.
- Define the member functions of 'GeometryEngine' AFTER 'Rectangle' is fully defined
  so the compiler knows the private layout of 'Rectangle'.

REQUIREMENTS:
1. Class 'Rectangle':
   - Private members: float length, width;
   - Public methods: void setDimensions(float l, float w);
   - Friend declaration: friend class GeometryEngine;
2. Class 'GeometryEngine':
   - float calculateArea(Rectangle r)      -> returns length * width
   - float calculatePerimeter(Rectangle r) -> returns 2 * (length + width)
   - bool isSquare(Rectangle r)            -> returns true if length == width, else false
3. In main():
   - Take length and width from user input.
   - Set the dimensions of a Rectangle object.
   - Use a GeometryEngine object to compute and print the Area, Perimeter,
     and whether the rectangle is a square or not.
================================================================================
*/

#include <iostream>
using namespace std;

class GeometryEngine;

class Rectangle
{
   float l, b;
   friend class GeometryEngine;

public:
   void setdata(float a, float m);
};

void Rectangle::setdata(float a, float m)
{
   l = a;
   b = m;
}

class GeometryEngine
{
   float area, perimeter;

public:
   void calcarea(Rectangle r1);
   void calcperimeter(Rectangle r1);
   void issquare(Rectangle r1);
};

void GeometryEngine::calcarea(Rectangle r1)
{
   area = r1.l * r1.b;
   cout << endl
        << "Area of rectangle is : " << area << endl;
}

void GeometryEngine::calcperimeter(Rectangle r1)
{
   perimeter = 2 * (r1.l + r1.b);
   cout << "perimeter of rectangle is : " << perimeter << endl;
}

void GeometryEngine::issquare(Rectangle r1)
{

   cout << "It is a square :";

   if (r1.l == r1.b)
   {
      cout << " True" << endl;
   }

   else
   {
      cout << " False" << endl;
   }
}

int main()
{
   float a, m;
   cout << "Enter Length of rectangle : ";
   cin >> a;
   cout << endl
        << "Enter Breadth of rectangle : ";
   cin >> m;

   Rectangle r1;

   r1.setdata(a, m);

   GeometryEngine g1;
   g1.calcarea(r1);
   g1.calcperimeter(r1);
   g1.issquare(r1);

   return 0;
}
