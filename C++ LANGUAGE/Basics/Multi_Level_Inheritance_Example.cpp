#include <iostream>
using namespace std;
class add
{
protected:
    int sum, num1, num2;

public:
    void getdata()
    {
        cout << "Enter Vale num1 and num2 : ";
        cin >> num1 >> num2;
    }
    void display_add()
    {
        getdata();
        sum = num1 + num2;
        cout << "Sum of Nunmbers = " << sum << "\n";
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
        cout << "Difference of Numbers : " << sub << "\n";
    }
};

class multiply : public subtract
{
    int multi;

public:
    void display_multi()
    {
        getdata();
        multi = num1 * num2;
        cout << "Product of Numbers : " << multi << "\n";
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