// Create a Student class with name, roll number and CGPA. Create an object and display its details.
#include <iostream>
using namespace std;
class Student{
    public:
    string name;
    int rollNumber;
    float CGPA;
};
int main(){
    Student Rhitam;
    Rhitam.name="Rhitam";
    Rhitam.rollNumber=41;
    Rhitam.CGPA=9.67;

    Student Sumedh;
    Sumedh.name="Sumedh";
    Sumedh.rollNumber=26;
    Sumedh.CGPA=9.6;

    Student Atharv;
    Atharv.name="Atharv";
    Atharv.rollNumber=3;
    Atharv.CGPA=9.69;

    cout<<"Student name: "<<Rhitam.name<<", "<<"Roll Number: "<<Rhitam.rollNumber<<", "<<"CGPA: "<<Rhitam.CGPA<<endl;
    cout<<"Student name: "<<Sumedh.name<<", "<<"Roll Number: "<<Sumedh.rollNumber<<", "<<"CGPA: "<<Sumedh.CGPA<<endl;
    cout<<"Student name: "<<Atharv.name<<", "<<"Roll Number: "<<Atharv.rollNumber<<", "<<"CGPA: "<<Atharv.CGPA<<endl;
    return 0;
}
