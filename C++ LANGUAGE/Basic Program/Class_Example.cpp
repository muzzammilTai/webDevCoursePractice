/*
    Example : Class Implementation.
*/
#include <iostream>
using namespace std;

// Class defination.
class addition
{
    // by default private.
    int sum, num1, num2; // Member variable declaration.
public:                  // access modifier.
    // member function declaration and defination.
    void getdata()
    {
        cout << "Enter the value of num1 and num2 : ";
        cin >> num1 >> num2;
    }
    void display()
    {
        sum = num1 + num2;
        cout << "Sum of numbers = " << sum << "\n";
    }
};

int main()
{
    // object creation.
    addition add; // addition is classname and add is the object of the class.
    // function calling
    add.getdata();
    add.display();
    return 0;
}