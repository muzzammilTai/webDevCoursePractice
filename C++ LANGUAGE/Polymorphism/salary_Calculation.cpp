#include <iostream>
#include<string.h>
using namespace std;
class salaryCalculation
{
    char n[100];
    double basicPay, specialAlw, conveyanceAlw, gross, pf, netSalary, AnnualSal;

public:
    salaryCalculation(char name[], double bpay)
    {
        strcpy(n, name);
        conveyanceAlw = 1000.00;
        basicPay = bpay;
    }
    void Salarycal()
    {
        pf = 1000;
        specialAlw = 0.25 * basicPay;
        gross = basicPay + specialAlw + conveyanceAlw;
        netSalary = gross - pf;
        AnnualSal = 12 * netSalary;
    }
    void display()
    {
        cout << "Employee Name : " << n << "\nBasic Pay : " << basicPay << "\nSpecial Allowance : " << specialAlw << "\nNet Salary : " << netSalary << "\nAnnual Salary : "<<AnnualSal<<"\n";
    }
};

int main()
{
    char name[100];
    salaryCalculation sc("DEMO", 10000);
    sc.Salarycal();
    sc.display();
    return 0;
}