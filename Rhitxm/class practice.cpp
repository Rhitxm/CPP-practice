// Matilda, Roald Dahl, 1998
// The Giving Tree, Shel Silverstein, 1964
//Print the following output
#include <iostream>
using namespace std;
class book{
    public:
    string title;
    string author;
    int year;
};
int main(){
    book Book1;
    // Matilda, Roald Dahl, 1988
    Book1.title="Matilda";
    Book1.author="Roald Dahl";
    Book1.year=1998;

    book Book2;
    // The Giving Tree, Shel Silverstein, 1964
    Book2.title="The Giving Tree";
    Book2.author="Shel Silverstein";
    Book2.year=1964;

    cout<<Book1.title<<", "<<Book1.author<<", "<<Book1.year<<endl;
    cout<<Book2.title<<", "<<Book2.author<<", "<<Book2.year<<endl;
    return 0;
}
