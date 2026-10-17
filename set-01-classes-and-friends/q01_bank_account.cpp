/*
================================================================================
PROBLEM 01: Bank Account Management (Basic Classes & Access Specifiers)
--------------------------------------------------------------------------------
OBJECTIVE:
Create a 'BankAccount' class to practice basic OOP encapsulation, data hiding,
and separation of public vs private members.

REQUIREMENTS:
1. Private Data Members:
   - string depositorName
   - long accountNumber
   - string accountType
   - double balance
2. Public Member Functions:
   - void setInitialValues(...) : Assigns initial customer and balance data.
   - void deposit(double amount) : Adds money to balance.
   - void withdraw(double amount): Deducts money if sufficient balance exists;
                                   shows error message if insufficient funds.
   - void displayAccount()       : Prints account holder name and current balance.
3. In main():
   - Create an account object, initialize it, test deposit and withdrawal,
     and display final balance.
================================================================================
*/



#include <iostream>
using namespace std;

class bank
{
    long accountno = 1001;
    double balance = 100000;

    // Private helper: returns true if funds are sufficient
    bool checkbalance(double amount)
    {
        return (amount <= balance);
    }

    // Private helper: returns true if the input amount is positive
    bool isValidAmount(double amount)
    {
        return (amount > 0);
    }

public:
    void deposit(double amount);
    void withdraw(double amount);
    void display();
};

void bank::deposit(double amount)
{
    if (!isValidAmount(amount))
    {
        cout << "Invalid deposit amount! Amount must be positive." << endl;
        return;
    }
    balance += amount;
    cout << "Deposit successful!" << endl;
    display();
}

void bank::withdraw(double amount)
{
    if (!isValidAmount(amount))
    {
        cout << "Invalid withdrawal amount! Amount must be positive." << endl;
        return;
    }

    if (!checkbalance(amount))
    {
        cout << "Error: Insufficient balance!" << endl;
        return;
    }

    balance -= amount;
    cout << "Withdrawal successful!" << endl;
    display();
}

void bank::display()
{
    cout << "Your current balance is: " << balance << endl;
}

int main()
{
    int option;
    double amount;
    bank c1;

    do
    {
        cout << "\nChoose one of the following options:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1)
        {
        }
        else if (option == 2)
        {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            c1.withdraw(amount);
        }
        else if (option == 3)
        {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            c1.deposit(amount);
        }
        else if (option == 4)
        {
            cout << "Thank you for banking with us!" << endl;
        }
        else
        {
            cout << "Invalid choice! Please select 1-4." << endl;
        }

    } while (option != 4);

    return 0;
}
