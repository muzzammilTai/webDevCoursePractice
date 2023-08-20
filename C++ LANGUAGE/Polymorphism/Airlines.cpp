#include <iostream>
using namespace std;
class Airlines
{

public:
    char n[30], dc;
    double d, t, r, no;
    double p;
    void booking()
    {
        cout << "Enter Number of Passengers : ";
        cin >> no;
        cout << "Enter the Name of a Passenger / Group Head : ";
        cin >> n;
        cout << "Choose Destination : \nPress A : AMERICA\nPress S : SINGAPORE\nPress J : JAPAN\nPress T : THAILAND\n";
        cout << "Enter the Destination Code : ";
        cin >> dc;
    }

    void price()
    {
        if (dc == 'A')
        {
            r = 50000.00;
            p = r * no;
        }
        else if (dc == 'S')
        {
            r = 20000.00;
            p = r * no;
        }
        else if (dc == 'J')
        {
            r = 40000.00;

            p = r * no;
        }
        else if (dc == 'T')
        {
            r = 30000.00;
            p = r * no;
        }
        cout << "PRICE : " << p << "\n";
    }

    void discount()
    {
        if (p >= 200000)
        {
            d = p * 0.25;
        }
        else if (p >= 150001 && p < 200000)
        {
            d = p * 0.20;
        }
        else if (p >= 100001 && p < 150000)
        {
            d = p * 0.15;
        }
        else if (p <= 100000)
        {
            d = p * 0.10;
        }
    }

    void netamount()
    {
        t = p - d;
    }

    void display()
    {
        cout << "\nName : " << n << "\nNo. of Passengers : " << no << "\nDestination Code : " << dc << "\nDiscount : " << d << "\nTotal Amount : " << t << "\n";
    }
};

int main()
{
    Airlines user;
    user.booking();
    user.price();
    user.discount();
    user.netamount();
    user.display();
}