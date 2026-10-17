/*
================================================================================
PROBLEM 04: Object Counter (Static Data Members & Static Member Functions)
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate class-level shared state across multiple objects using static members
and calling static functions via the class scope resolution operator (::).

REQUIREMENTS:
1. Private Data Members:
   - int itemId        : Unique ID for each individual object instance.
   - static int count  : Shared counter tracking total items; must be defined
                         outside the class using 'int item::count = 0;'.
2. Public Member Functions:
   - void setdata(int id)    : Sets item ID and increments static count by 1.
   - void getdata()          : Prints the individual item's ID.
   - static void showcount() : Class-level function that prints total count;
                               can only access static members.
3. In main():
   - Call item::showcount() before creating objects, after setting data, and
     verify that all objects share the same common count value.
================================================================================
*/

#include <iostream>
using namespace std;

class item
{
    static int count;
    int itemId;

public:
    void setdata(int id);
    void getdata();
    static void showcount();
};

int item::count = 0;

void item::showcount()
{
    cout << "No of items are : " << count << endl;
}

void item::setdata(int id)
{
    itemId = id;
    count++;
}

void item::getdata()
{
    cout << "Item id : " << itemId << endl;
}

int main()
{
    item::showcount(); // special way to call static function
    item i1, i2, i3;
    i1.setdata(101);
    i2.setdata(102);
    item::showcount();
    i3.setdata(103);
    item::showcount();

    cout << "\n--- Item Details ---" << endl;
    i1.getdata();
    i2.getdata();
    i3.getdata();

    return 0;
}
