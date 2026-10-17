/*
================================================================================
PROBLEM 05: Store Inventory (Array of Objects & Getter Methods)
--------------------------------------------------------------------------------
OBJECTIVE:
Manage multiple objects using an array of objects, handle multi-word string input
with buffer clearing, and safely inspect private data using a getter function.

REQUIREMENTS:
1. Private Data Members:
   - int id
   - string name
   - float price
2. Public Member Functions:
   - void setData(int pId, string pName, float pPrice) : Initializes product fields.
   - void displayData(int index)                       : Prints product details.
   - float getPrice()                                  : Public getter returning
                                                         private price for comparisons.
3. In main():
   - Create an array: Product store[3].
   - Use a loop with cin >> and getline(cin, name) (using cin.ignore() between them)
     to take product inputs.
   - Traverse the array using store[i].getPrice() to find and display the item
     with the highest price.
================================================================================
*/


/*
================================================================================
                       ESSENTIAL C++ STRING CHEAT SHEET
                       Header Required: #include <string>
================================================================================

1. INPUT / OUTPUT:
   cin >> s;              // Reads a single word (stops at whitespace/space)
   getline(cin, s);       // Reads entire line with spaces until Enter (\n)
   cin.ignore();          // Clears buffer; MUST use before getline() if preceded by cin >>
   cout << s;             // Replaces puts(); prints string automatically

2. LENGTH & CAPACITY:
   s.length();            // Returns number of characters (O(1) time complexity)
   s.size();              // Identical to s.length()
   s.empty();             // Returns true (1) if string is empty (""), false (0) otherwise
   s.clear();             // Erases all characters; makes string empty

3. ACCESS & MODIFICATION:
   s[i];                  // Direct array-like index access (0-indexed, unchecked)
   s.at(i);               // Safe index access (throws out_of_range exception if invalid)
   s.front();             // Accesses first character (same as s[0])
   s.back();              // Accesses last character (same as s[s.length() - 1])
   s.push_back('c');      // Appends single character 'c' to the end
   s.pop_back();          // Removes the last character from the end

4. CONCATENATION & COMPARISON:
   s1 + s2;               // Concatenates two strings together
   s1 += s2;              // Appends s2 directly to s1
   s.append("text");      // Alternative way to append text to the end
   s1 == s2;              // Returns true if contents match (replaces strcmp == 0)
   s1 != s2;              // Checks inequality
   s1 < s2;               // Lexicographical (alphabetical/ASCII) comparison

5. SEARCH & SUBSTRING:
   s.find("abc");         // Returns starting index of "abc", or string::npos if not found
   s.substr(pos, len);    // Extracts a sub-string starting at 'pos' of length 'len'
   s.replace(pos, len, "new"); // Replaces 'len' chars starting at 'pos' with "new"

6. C-COMPATIBILITY:
   s.c_str();             // Converts std::string to const char* (null-terminated '\0')
================================================================================
*/

#include <iostream>
#include <string>

using namespace std;

class product
{
    int id;
    string name;
    float price;

public:
    void setData(int pId, string pName, float pPrice);
    void displayData(int i);
    float getPrice();
};

void product::setData(int pId, string pName, float pPrice)
{
    id = pId;
    name = pName;
    price = pPrice;
}

void product::displayData(int i)
{
    cout << "\n\nProduct " << i << endl;
    cout << " Name : " << name << endl;
    cout << " Id : " << id << endl;
    cout << " Price : " << price << endl;
}

float product::getPrice()
{
    return price;
}

int main()
{
    product store[3];
    int pId;
    string pName;
    float pPrice;

    for (int i = 0; i < 3; i++)
    {
        cout << "\nEnter details for product " << (i + 1) << ":" << endl;
        cout << "Enter ID: ";
        cin >> pId;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, pName);
        cout << "Enter Price: ";
        cin >> pPrice;

        store[i].setData(pId, pName, pPrice);
    }

    cout << endl
         << endl
         << "------- Available products -------" << endl;

    for (int i = 0; i < 3; i++)
    {
        store[i].displayData(i + 1);
    }

    int maxIndex = 0;

    for (int i = 1; i < 3; i++)
    {
        if (store[i].getPrice() > store[maxIndex].getPrice())
        {
            maxIndex = i; // Save the position of the winning product
        }
    }

    cout << "\n===============================" << endl;
    cout << "    MOST EXPENSIVE PRODUCT     " << endl;
    cout << "===============================";
    store[maxIndex].displayData(maxIndex + 1);
    return 0;
}
