// Example of Single Inheritance.
#include <iostream>
using namespace std;

// Base class or parent class or super class.
class add
{
protected: // visibility mode.
    int sum, num1, num2;

public:
    void getdata()
    {
        cout << "Enter the Value of num1 and num2 : ";
        cin >> num1 >> num2;
    }
    void display_add()
    {
        getdata();
        sum = num1 + num2;
        cout << "Sum of numbers = " << sum << "\n";
    }
};

// Derived class or child class or subclass.
class subtract : public add
{
    int sub;

public:
    void display_sub()
    {
        display_add();
        getdata();
        sub = num1 - num2;
        cout << "Difference of numbers = " << sub << "\n";
    }
};
int main()
{
    subtract s;      // creating child class object.
    s.display_sub(); // creating child class function.
    return 0;
}