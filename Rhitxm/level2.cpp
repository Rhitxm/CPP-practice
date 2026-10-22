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


//Reverse an integer without converting it to a string. Example: 12340 → 4321.
#include <iostream>
using namespace std;
int main(){
    int n, rem, rev=0;
    cout<<"Enter a number: "<<endl;
    cin>>n;
    cout<<"Entered digit is: "<<n<<endl;
    while(n!=0){
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    cout<<"Reversed digit is: "<<rev<<endl;
    return 0;
}
