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
//OUTPUT
// ------Student Details------
 
// Name: Rhitam
// Roll Number: 41
// CGPA: 9.67
 
// Name: Sumedh
// Roll Number: 26
// CGPA: 9.69





//Create a Complex class with real and imaginary parts. Initialise them using a constructor and display the complex number.
#include <iostream>
using namespace std;
class Complex{
    public:
    int a;
    int b;
    Complex(int x, int y);
};
Complex::Complex(int x, int y){
    a=x;
    b=y;
}
int main(){
    Complex c1(1, 3);
    Complex c2(4, 2);
    cout<<"Complex Number 1 is: "<<c1.a<<"+"<<c1.b<<"i"<<endl;
    cout<<"Complex number 2 is: "<<c2.a<<"+"<<c2.b<<"i"<<endl;
    return 0;
}
//OUPUT:
// Complex Number 1 is: 1+3i
// Complex number 2 is: 4+2i
