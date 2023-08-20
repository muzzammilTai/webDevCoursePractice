#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
protected:
    char name[100], designation[100];
    int no;

public:
    Employee(char n[], char d[], int o)
    {
        strcpy(name, n);
        strcpy(designation, d);
        no = o;
    }
    void display()
    {
        cout << "\nEmployee Name : " << name << "\nDesignation : " << designation << "\nno. : " << no << "\n";
    }
};

class salary : public Employee
{
    float sal, basic, DA, HRA, PF, net;

public:
    salary(char n[], char d[], int o, float sa) : Employee(n, d, o)
    {
        basic = sa;
    }
    void calculate()
    {
        display();
        DA = 0.10 * basic;
        HRA = 0.15 * basic;
        sal = basic + DA + HRA;
        cout << "Salary = " << sal << "\n";
        PF = 0.08 * sal;
        net = sal - PF;
        cout << "Net Salary = " << net << "\n";
    }
};

int main()
{
    char n[100], d[100];
    int o;
    float sa;
    cout << "Enter Employee Number : ";
    cin >> o;
    cout << "Enter Employee Name : ";
    cin >> n;
    cout << "Enter Employee Designation : ";
    cin >> d;
    cout << "Enter Employee Salary : ";
    cin >> sa;
    salary s(n, d, o, sa);
    s.calculate();
    return 0;
}