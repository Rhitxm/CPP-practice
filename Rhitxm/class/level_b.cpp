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





// Create a Rectangle class with overloaded constructors: one with no arguments and another with length and breadth.
#include <iostream>
using namespace std;
class Rectangle{
    public:
    int length;
    int breadth;
    Rectangle(){
        length=0;
        breadth=0;
    }
    Rectangle(int l, int b){
        length=l;
        breadth=b;
    }
};
int main(){
    Rectangle r1;
    Rectangle r2(2, 3);
    Rectangle r3(4, 9);
    cout<<"----Rectangle Details----"<<endl;
    cout<<"For rectangle 1, length is: "<<r1.length<<" and breadth is: "<<r1.breadth<<endl;
    cout<<"For rectangle 2, length is: "<<r2.length<<" and breadth is: "<<r2.breadth<<endl;
    cout<<"For rectangle 3, length is: "<<r3.length<<" and breadth is: "<<r3.breadth<<endl;
    return 0;
}
//OUTPUT
// ----Rectangle Details----
// For rectangle 1, length is: 0 and breadth is: 0
// For rectangle 2, length is: 2 and breadth is: 3
// For rectangle 3, length is: 4 and breadth is: 9
