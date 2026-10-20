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
