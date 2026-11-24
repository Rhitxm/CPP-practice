// Create a Student class with name, roll number and CGPA and initialise its data members using a parameterised constructor.
#include <iostream>
using namespace std;
class Student{
    public:
    string name;
    int rollNumber;
    double cgpa;
    Student(string x, int y, double z);
};
Student::Student(string x, int y, double z){
    name=x;
    rollNumber=y;
    cgpa=z;
}
int main(){
    Student s1("Rhitam", 41, 9.67);
    Student s2("Sumedh", 26, 9.69);
    cout<<"------Student Details------"<<endl;
    cout<<" "<<endl;
    cout<<"Name: "<<s1.name<<endl;
    cout<<"Roll Number: "<<s1.rollNumber<<endl;
    cout<<"CGPA: "<<s1.cgpa<<endl;
    cout<<" "<<endl;
    cout<<"Name: "<<s2.name<<endl;
    cout<<"Roll Number: "<<s2.rollNumber<<endl;
    cout<<"CGPA: "<<s2.cgpa<<endl;
    return 0;
}

