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


//Store n integers in an numay and calculate the sum, average, largest element and smallest element.
#include <iostream>
using namespace std;

int main(){
    int sum, average;
    int n=4;
    int num[6]={23, 25, 26, 27};
    sum=num[0]+num[1]+num[3]+num[4];
    cout<<"Sum of the stored values is: "<<sum<<endl;
    average=(num[0]+num[1]+num[3]+num[4])/4;
    cout<<"The average of the entered values are: "<<average<<endl;
    int largest=num[0];
    int smallest=num[0];

    for(int i=1; i<n; i++){
        if(num[i]>largest){
            largest=num[i];
        }
        if(num[i]<smallest){
            smallest=num[i];
        }
    }
    cout<<"Largest element from the given set is: "<<largest<<endl;
    cout<<"Smallest element from the given set is: "<<smallest<<endl;

    return 0;
}
