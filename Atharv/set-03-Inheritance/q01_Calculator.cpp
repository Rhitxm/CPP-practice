/*
Create 2 classes:
    1. SimpleCalculator - Takes input of 2 numbers using a utility function and performs +, -, *, / and displays the results using another function.
    2. ScientificCalculator - Takes input of 2 numbers using a utility function and performs any four scientific operations of your choice and displays the results using another function.

    Create another class HybridCalculator and inherit it using these 2 classes:
    Q1. What type of Inheritance are you using?
    Q2. Which mode of Inheritance are you using?
    Q3. Create an object of HybridCalculator and display results of the simple and scientific calculator.
    Q4. How is code reusability implemented?
*/

#include <iostream>
#include <cmath>

using namespace std;

class SimpleCalculator
{
protected:
    float a, b;

public:
    void setSimpleData(float x, float y)
    {
        a = x;
        b = y;
    }

    float add();
    float subtract();
    float multiply();
    float quotient();
    int remainderOp();
};

float SimpleCalculator::add()
{
    return (a + b);
}
float SimpleCalculator::subtract()
{
    return (a - b);
}
float SimpleCalculator::multiply()
{
    return (a * b);
}
float SimpleCalculator::quotient()
{
    if (b != 0)
        return a / b;
    cout << "Error: Division by zero!" << endl;
    return 0;
}
int SimpleCalculator::remainderOp()
{
    if (int(b) != 0)
        return int(a) % int(b);
    cout << "Error: Modulo by zero!" << endl;
    return 0;
}

class ScientificCalculator
{
protected:
    float p, q;

public:
    void setScientificData(float x, float y = 0)
    {
        p = x;
        q = y;
    }

    float squareroot()
    {
        return sqrt(p);
    }
    float power()
    {
        return pow(p, q);
    }
    float calcsin()
    {
        return sin(p);
    } // In radians

    long long factorial()
    {
        if (p < 0)
            return -1;
        long long fact = 1;
        for (int i = 1; i <= int(p); i++)
        {
            fact *= i;
        }
        return fact;
    }
};
class Calculator : public SimpleCalculator, public ScientificCalculator
{
public:
    void displayAllResults()
    {
        cout << "\n--- Simple Calculator Results ---" << endl;
        cout << "Addition: " << add() << endl;
        cout << "Subtraction: " << subtract() << endl;
        cout << "Multiplication: " << multiply() << endl;
        cout << "Quotient: " << quotient() << endl;
        cout << "Remainder: " << remainderOp() << endl;

        cout << "\n--- Scientific Calculator Results ---" << endl;
        cout << "Square Root of " << p << ": " << squareroot() << endl;
        cout << p << " raised to power " << q << ": " << power() << endl;
        cout << "Factorial of " << int(p) << ": " << factorial() << endl;
        cout << "Sin(" << p << " rad): " << calcsin() << endl;
    }
};

int main()
{
    Calculator calc;
    calc.setSimpleData(10, 4);
    calc.setScientificData(5, 3);
    calc.displayAllResults();

    return 0;
}
