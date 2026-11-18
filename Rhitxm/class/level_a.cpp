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

// Create an Employee class with employee ID, name and salary. Take input and display the information.
#include <iostream>
using namespace std;
class Employee{
    public:
    int EmpId;
    string name;
    float salary;
};
int main(){
    int n;
    cout<<"Enter number of employees: ";
    cin>>n;
   Employee emp[100];
   for(int i=1; i<=n; i++){
    cout<<"\nEnter details of the employee: "<<i<<endl;
    cout<<"Enter employee ID: ";
    cin>>emp[i].EmpId;
    cout<<"Enter name: ";
    cin>>emp[i].name;
    cout<<"Enter salary: ";
    cin>>emp[i].salary;
   }

   cout<<"\n------Employee Details------\n";
   for(int i=1; i<=n; i++){
    cout<<"Employee ID is: "<<emp[i].EmpId<<endl;
    cout<<"Name is: "<<emp[i].name<<endl;
    cout<<"Salary is: "<<emp[i].salary<<endl;
   }
    return 0;
}
