#include <iostream>
#include <string.h>
using namespace std;
class product
{
protected:
    char name[100];
    int code;
    double amount;

public:
    product(char n[], int c, double p)
    {
        strcpy(name, n);
        code = c;
        amount = p;
    }
    void show()
    {
        cout << "\nProduct's Name : " << name << "\nCode : " << code << "\nAmount : " << amount << "\n";
    }
};

class sales : public product
{
    int day;
    double tax, totamt;

public:
    sales(char n[], int c, double p, int d) : product(n, c, p)
    {
        day = d;
    }
    void compute()
    {
        tax = 0.124 * amount;
        if (day > 30)
        {
            totamt = amount + tax + (0.025 * amount);
        }
        else
        {
            totamt = amount + tax;
        }
    }
    void display()
    {
        show();
        compute();
        cout << "\nTotal Amount = " << totamt << "\n";
    }
};

int main()
{
    char n[100];
    int c, d;
    double p;
    cout << "Enter Product's Name : ";
    cin >> n;
    cout << "Enter Product's Code : ";
    cin >> c;
    cout << "Enter Product's Amount : ";
    cin >> p;
    cout << "Enter Number of days taken to pay the sale amount : ";
    cin >> d;
    sales s(n, c, p, d);
    s.display();
    return 0;
}