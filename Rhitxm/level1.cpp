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
