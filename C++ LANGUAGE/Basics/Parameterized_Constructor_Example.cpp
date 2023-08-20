#include <iostream>
using namespace std;

class constructorExample
{
    int sum, n1, n2;

public:
    constructorExample()
    {
        n1 = 100;
        n2 = 200;
    }
    constructorExample(int a, int b)
    {
        n1 = a;
        n2 = b;
    }
    void display()
    {
        sum = n1 + n2;
        cout << "Sum of numbers = " << sum << "\n";
    }
};

int main()
{
    int num1, num2;
    constructorExample ce;
    cout << "Default Constructer :\n";
    ce.display();

    cout << "\nEnter the value of num1 and num2 : ";
    cin >> num1 >> num2;
    constructorExample ce_p(num1, num2);
    cout << "Parameterized Constructor :\n";
    ce_p.display();
}