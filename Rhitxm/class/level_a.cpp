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
//OUTPUT:
// Student name: Rhitam, Roll Number: 41, CGPA: 9.67
// Student name: Sumedh, Roll Number: 26, CGPA: 9.6
// Student name: Atharv, Roll Number: 3, CGPA: 9.69



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
//OUTPUT:
// Enter number of employees: 1

// Enter details of the employee: 1
// Enter employee ID: 1
// Enter name: rhitam
// Enter salary: 250000\

// ------Employee Details------
// Employee ID is: 1
// Name is: rhitam
// Salary is: 250000



// Create a Rectangle class with length and breadth. Write functions to calculate area and perimeter.
#include <iostream>
using namespace std;
class Rectangle{
    public:
    int length;
    int breadth;
};
int AreaOfRectangle(int length, int breadth){
    int area;
    area=length*breadth;
    return area;
}
int PerimeterOfRectangle(int length, int breadth){
    int perimeter;
    perimeter=2*(length+breadth);
    return perimeter;
}
int main() 
{
    int x, y;
    cout<<"Enter length: ";
    cin>>x;
    cout<<"Enter breadth: ";
    cin>>y;
    int n;
    cout<<"\n1.Perimeter"<<"\n2.Area\n";
    cout<<"Enter your choice: ";
    cin>>n;
    cout<<"----Results----"<<endl;
    switch(n){
        case 1:
        cout<<"Perimeter is: "<<PerimeterOfRectangle(x, y)<<endl;
        break;
        case 2:
        cout<<"Area is: "<<AreaOfRectangle(x, y)<<endl;
    }
    return 0;
}
//OUTPUT:
// Enter length: 2
// Enter breadth: 4

// 1.Perimeter
// 2.Area
// Enter your choice: 2
// ----Results----
// Area is: 8


// Create a BankAccount class with account number and balance. Implement deposit and withdrawal functions.
#include <iostream>
#include<iomanip> //for displaying digits without scientific notation
using namespace std;
class BankAcc{
    public:
    int accNumber;
    private:
    double bal=6900000.00; //stipulated fixed amount
    public:
    void display(){
        cout<<"Balance in account is: "<<bal<<endl;
    }
void deposit(double d){
    bal=bal+d;
    cout<<"Current balance after depositing rupees "<<d<<" is "<<bal<<endl;
}
void withdrawal(double w){
    if(w>bal){
        cout<<"Insufficient Balance!!"<<endl;
    }
    else{
    bal=bal-w;
    cout<<"Current balance after withdrawing rupees "<<w<<" is "<<bal<<endl;
    }
}
};
int main(){
    cout<<fixed<<setprecision(2); //displays only 2 digits after the decimal
    BankAcc account;
    int n;
    double amount;
    cout<<"Enter your account number: ";
    cin>>account.accNumber;
    account.display();
    cout<<"Enter your choice: "<<"\n1.Deposit\n"<<"\n2.Withdrwal"<<endl;
    cin>>n;
    switch(n){
        case 1:
        cout<<"Enter amount to be deposited: ";
        cin>>amount;
        account.deposit(amount);
        break;
        case 2:
        cout<<"Enter amount to be withdrawn :";
        cin>>amount;
        account.withdrawal(amount);
        break;
        default:
        cout<<"No option was chosen"<<endl;
    }
    return 0;
}
//OUTPUT
// Enter your account number: 123
// Balance in account is: 6900000.00
// Enter your choice: 
// 1.Deposit

// 2.Withdrwal
// 1
// Enter amount to be deposited: 20
// Current balance after depositing rupees 20.00 is 6900020.00




// Create a Car class with brand, model and speed. Implement functions to accelerate and brake.
#include <iostream>
#include<iomanip>
using namespace std;
class car{
    public:
    string brand;
    int model;
    double speed;
};
int main(){
    cout<<fixed<<setprecision(2);
    int n;
    cout<<"Enter number of cars to be registered: ";
    cin>>n;
    car Car[100];
    for(int i=1; i<=n; i++){
        cout<<"Enter details of the car "<<i<<endl;
        cout<<"Enter brand name: "<<Car[i].brand<<endl;
        cout<<"Enter model: "<<Car[i].model<<endl;
        cout<<"Enter speed: "<<Car[i].speed<<endl;
    }
    cout<<"Enter number of car you want to change speed of: "<<endl;
    cin>>i;
    return 0;
}
