/*
================================================================================
PROBLEM 02: Time Addition (Passing Objects as Function Arguments)
--------------------------------------------------------------------------------
OBJECTIVE:
Create a 'Time' class to demonstrate passing objects to member functions and
normalizing values when combining units.

REQUIREMENTS:
1. Private Data Members:
   - int hour
   - int minute
2. Private Helper Function:
   - void timenormalize() : Converts every 60 minutes into 1 hour (using / and %).
3. Public Member Functions:
   - void settime(int h, int m) : Sets hours and minutes for an object.
   - void addtime(...)          : Adds time (either by accepting another Time
                                  object or time values) and normalizes minutes.
   - void displaytime()         : Prints time in standard format (HH:MM).
4. In main():
   - Create a base time object, accept extra time from the user, add it,
     and display the updated normalized time.
================================================================================
*/

#include <iostream>
using namespace std;

class Time
{
    int hour;
    int minute;

public:
    void settime(int h, int m);
    void addtime(Time t1, Time t2);
    void timenormalize();
    void displaytime();
};

void Time::displaytime()
{
    cout << "Current time is: ";
    if (hour < 10)
        cout << "0";
    cout << hour << " : ";
    if (minute < 10)
        cout << "0";
    cout << minute << endl;
}
void Time::timenormalize()
{

    while (minute >= 60)
    {

        minute -= 60;
        hour += 1;
    }

    while (hour >= 24)
    {
        hour -= 24;
    }
}
void Time::settime(int h, int m)
{
    hour = h;
    minute = m;
    timenormalize();
    displaytime();
}
void Time::addtime(Time t1, Time t2) // note
{
    hour = t1.hour + t2.hour;
    minute = t2.minute + t1.minute;
    timenormalize();
    displaytime();
}

int main()
{
    Time t1, t2, t3;
    int h, m;

    cout << "--- Enter First Time ---" << endl;
    cout << "Enter hour: ";
    cin >> h;
    cout << "Enter minute: ";
    cin >> m;
    t1.settime(h, m);
    cout << "\n--- Enter Second Time to Add ---" << endl;
    cout << "Enter hour: ";
    cin >> h;
    cout << "Enter minute: ";
    cin >> m;
    t2.settime(h, m);
    cout << "\nTime 1: ";
    t1.displaytime();
    cout << "Time 2: ";
    t2.displaytime();
    t3.addtime(t1, t2);
    cout << "\nResultant Time after addition: ";
    t3.displaytime();
    return 0;
}