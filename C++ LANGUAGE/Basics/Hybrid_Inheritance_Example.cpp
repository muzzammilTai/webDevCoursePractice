#include <iostream>
using namespace std;
class add
{
protected:
    int sum, num1, num2;

public:
    void getdata()
    {
        cout << "Enter the value of num1 and num2 : ";
        cin >> num1 >> num2;
    }
    void display_add()
    {
        getdata();
        sum = num1 + num2;
        cout << "Sum of numbers = " << sum << "\n";
    }
};
class subtract : public add
{
    int sub;

public:
    void display_sub()
    {
        getdata();
        sub = num1 - num2;
        cout << "Differrence of numbers = " << sub << "\n";
    }
};

class divide
{
protected:
    void display_Division()
    {
        int div, num1, num2;
        cout << "Enter the Value of num1 and num2 : ";
        cin >> num1 >> num2;
        div = num1 / num2;
        cout << "Division of numbers : " << div << "\n";
    }
};
class multiply : public subtract, public divide
{
    int multi;

public:
    void display_multi()
    {
        getdata();
        multi = num1 * num2;
        cout << "Product of numbers = " << multi << "\n";
        display_Division();
    }
};

int main()
{
    multiply m;
    m.display_add();
    m.display_sub();
    m.display_multi();
    return 0;
}