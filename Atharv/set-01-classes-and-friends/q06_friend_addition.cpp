/*
================================================================================
PROBLEM 06: Distance Addition (Friend Function Across Two Independent Classes)
--------------------------------------------------------------------------------
OBJECTIVE:
Use a global friend function and forward declaration to access and combine
the private data members of two completely independent classes.

REQUIREMENTS:
1. Forward Declaration:
   - Declare 'class distanceinches;' before 'class distancefeet;'.
2. Class 'distancefeet':
   - Private member: int feet
   - Public setter : void setdatafeet(int a)
   - Friend tag    : friend void adddistance(distancefeet d1, distanceinches d2);
3. Class 'distanceinches':
   - Private member: int inches
   - Public setter : void setdatainches(int b)
   - Friend tag    : friend void adddistance(distancefeet d1, distanceinches d2);
4. Global Friend Function (No Class Scope Resolution):
   - void adddistance(distancefeet d1, distanceinches d2)
     Accesses d1.feet and d2.inches, converts total to inches (1 ft = 12 in),
     computes final feet (/ 12) and remaining inches (% 12), and prints the result.
5. In main():
   - Take feet and inches from user, set them in their respective objects,
     and pass both objects to adddistance(f1, i1).
================================================================================
*/

#include <iostream>
using namespace std;

class distanceinches;

class distancefeet
{
    int feet;
    friend void adddistance(distancefeet d1, distanceinches d2);

public:
    void setdatafeet(int a);
};

void distancefeet::setdatafeet(int a)
{
    feet = a;
}

class distanceinches
{
    int inches;
    friend void adddistance(distancefeet d1, distanceinches d2);

public:
    void setdatainches(int b);
};

void distanceinches::setdatainches(int b)
{
    inches = b;
}

void adddistance(distancefeet d1, distanceinches d2)
{
    int total, finalfeet, finalinches;

    total = (d1.feet * 12) + d2.inches;
    finalfeet = total / 12;
    finalinches = total % 12;

    cout << "Total Distance: " << finalfeet << " feet and " << finalinches << " inches" << endl;
}

int main()
{

    distancefeet f1;
    distanceinches i1;
    int a, b;

    cout << "Enter Feet : ";
    cin >> a;

    cout << "Enter Inches : ";
    cin >> b;

    f1.setdatafeet(a);
    i1.setdatainches(b);

    adddistance(f1, i1);

    return 0;
}
