#include <iostream>
using namespace std;
class Employee
{
    char name[20];
    int pan, taxincome, tax;

public:
    Employee() {}
    void input()
    {
        cout << "Enter PAN Number : ";
        cin >> pan;
        cout << "Enter Name : ";
        cin >> name;
        cout << "Enter TaxIncome : ";
        cin >> taxincome;
    }
    void calc()
    {
        if (taxincome <= 100000)
        {
            tax = 0;
        }
        else if (taxincome >= 100001 && taxincome <= 150000)
        {
            tax = taxincome * 0.10;
        }
        else if (taxincome >= 150000 && taxincome <= 250000)
        {
            tax = taxincome * 0.20 + 5000;
        }
        else if (taxincome > 250000)
        {
            tax = taxincome * 0.30 + 25000;
        }
    }
    void display()
    {
        cout << "PAN  \tName      \tIncome    \tTAX\n"
             << pan << "\t" << name <<     "\t" << taxincome <<     "\t" << tax << "\t";
    }
};

int main()
{
    Employee user;
    user.input();
    user.calc();
    user.display();
    return 0;
}