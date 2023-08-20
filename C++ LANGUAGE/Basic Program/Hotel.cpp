#include <iostream>
using namespace std;
class hotel
{
    char name[20];
    double t_days;

public:
    double t_amt, d, r, net;
    void input()
    {
        cout << "Enter the Guest Name : ";
        cin >> name;
        cout << "Enter total number of days : ";
        cin >> t_days;
    }
    void calc()
    {
        t_amt = 850 * t_days;
        if (t_days <= 5)
        {
            r = 0.10;
        }
        else if (t_days > 5 && t_days <= 10)
        {
            r = 0.15;
        }
        else if (t_days > 10 && t_days <= 20)
        {
            r = 0.20;
        }
        else if (t_days > 20)
        {
            r = 0.25;
        }
        d = t_amt * r;
        net = t_amt - d;
    }
    void display()
    {
        cout << "One Day Charge : 850\nTotal amount : " << t_amt << "\nDiscount : " << d << "\nNet Amount : " << net << "\n";
    }
};

int main()
{
    hotel user;
    user.input();
    user.calc();
    user.display();
}