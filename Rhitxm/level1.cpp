//Take an integer as input and determine whether it is even or odd using if-else.

#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter your number: "<<endl;
    cin>>n;
    if(n%2!=0){
        cout<<"Entered number is odd"<<endl;
    }
    else{
        cout<<"Entered number is even"<<endl;
    }
    return 0;
}


//Print the multiplication table of a number up to 10 using a loop.
//i've used for loop here
#include <iostream>
using namespace std;

int main(){
    int n;
    int tab;
    cout<<"Enter your number you want table of: "<<endl;
    cin>>n;

    for(int i=1; i<=10; i++){
        tab=n*i;
        cout<<n<<"*"<<i<<" = "<<tab<<endl;
    }
    
    return 0;
}


//Input three integers and print the largest. Handle the case where two or more numbers are equal.

#include <iostream>
using namespace std;

int main(){
    int n1, n2, n3;
    int tab;
    cout<<"Enter your first number: "<<endl;
    cin>>n1;
    cout<<"Enter your second number: "<<endl;
    cin>>n2;
    cout<<"Enter your third number: "<<endl;
    cin>>n3;

    if(n1==n2==n3){
        cout<<"The entered numbers are equal"<<endl;
    }
    else if(n1==n2 && n1>n3){
        cout<<"Entered first and second numbers are equal and third number is lesser than them"<<endl;
    }
    else if(n1==n2 && n1<n3){
        cout<<"Entered first and second numbers are equal and third number is greater than them"<<endl;
    }
    else if(n1==n3 && n1>n2){
        cout<<"Entered first and third numbers are equal and second number is lesser than them"<<endl;
    }
    else if(n1==n3 && n1<n2){
        cout<<"Entered first and third numbers are equal and second number is greater than them"<<endl;
    }
    else if(n2==n3 && n2>n1){
        cout<<"Entered second and third numbers are equal and first number is lesser than them"<<endl;
    }
    else if(n2==n3 && n2<n1){
        cout<<"Entered second and third numbers are equal and first number is greater than them"<<endl;
    }
    else if(n1>n2 && n1>n3){
        cout<<"First entered number is the largest of all"<<endl;
    }
    else if(n2>n1 && n2>n3){
        cout<<"Second entered number is the largest of all"<<endl;
    }
    else if(n3>n1 && n3>n2){
        cout<<"Third entered number is the largest of all"<<endl;
    }
    return 0;
}


//Calculate the factorial of a number n. For example, 5! = 120. Handle n = 0.
#include <iostream>
using namespace std;

int main(){
    int n, factorial=1;
    cout<<"Enter a number: ";
    cin>>n;
    if(n==0){
        cout<<"Factorial of entered number is 0"<<endl;
    }
    else if(n!=0){
        for(int i=1; i<=n; i++){
            factorial=factorial*i;  
        }
        cout<<"Factorial of entered number is: "<<factorial<<endl;
    }
    return 0;
}
