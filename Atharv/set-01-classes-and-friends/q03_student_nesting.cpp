/*
================================================================================
PROBLEM 03: Student Report Card (Nesting of Member Functions)
--------------------------------------------------------------------------------
OBJECTIVE:
Demonstrate member function nesting where one member function internally calls
a private helper function without outside intervention.

REQUIREMENTS:
1. Private Data Members:
   - int rollno
   - float marks[3] (0-indexed: marks[0], marks[1], marks[2])
   - char grade
2. Private Member Function:
   - void gradecalculation() : Calculates the 3-subject average and assigns
                               'A' (avg >= 80), 'B' (avg >= 60), or 'C' (< 60).
                               Must NOT be callable directly from main().
3. Public Member Functions:
   - void input()            : Takes roll number and marks for 3 subjects, then
                               immediately invokes gradecalculation() (Nesting).
   - void displayreport()    : Displays roll number and final assigned grade.
4. In main():
   - Create a student object, call input(), and call displayreport().
================================================================================
*/

#include <iostream>
using namespace std;

class student
{
    float marks[3];
    int rollno = 0;
    char grade;
    void gradecalculation();

public:
    void input();
    void displayreport();
};

void student::gradecalculation()
{
    float a = marks[0] + marks[1] + marks[2];
    a /= 3;

    if (a >= 80)
    {
        grade = 'A';
    }
    else if (a >= 60)
    {
        grade = 'B';
    }
    else if (a < 60 && a > 0)
    {
        grade = 'C';
    }
    else
    {
        cout << "Invalid Makrs Entered" << endl;
    }
}

void student::input()
{
    cout << "------- Student Data --------" << endl
         << endl;
    cout << "Enter student rollno : ";
    cin >> rollno;
    cout << endl
         << "Enter Marks for subject 1 : ";
    cin >> marks[0];
    cout << endl
         << "Enter Marks for subject 2 : ";
    cin >> marks[1];
    cout << endl
         << "Enter Marks for subject 3 : ";
    cin >> marks[2];

    gradecalculation();
}

void student::displayreport()
{
    cout << endl
         << endl
         << "------ Student Report ------ " << endl
         << endl;
    cout << "Roll no. : " << rollno;
    cout << endl
         << "Grades : " << grade;
}

int main()
{
    student s1;

    s1.input();
    s1.displayreport();

    return 0;
}
