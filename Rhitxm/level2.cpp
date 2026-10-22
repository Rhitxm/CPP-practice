//Print the first n Fibonacci numbers using a loop. Example for n = 7: 0 1 1 2 3 5 8.
#include <iostream>
using namespace std;

int main(){
    int n, a=0, b=1, next;
    cout<<"Enter number of terms: "<<endl;
    cin>>n;
    cout<<"Fibonacci series: ";
    for(int i=1; i<=n; i++){
        cout<<a<<" ";
        next=a+b;
        a=b;
        b=next;
    }
    
    return 0;
}
