#include <iostream>
#include <string.h>
using namespace std;
class worker
{
protected:
    char n[100];
    int b;

public:
    worker(char na[], int ba)
    {
        strcpy(n, na);
        b = ba;
    }
    void display()
    {
        cout << "\nWorker Details:\nName : " << n << "\nBasic Pay : " << b << "\n";
    }
};
class wages : public worker
{
    int hrs, r, w, O;

public:
    wages(char na[], int ba, int h, int ra) : worker(na, ba)
    {
        hrs = h;
        r = ra;
    }
    void double_overtime()
    {
        O = hrs * r;
        w = O + b;
    }
    void dplay()
    {
        display();
        double_overtime();
        cout << "Wages : " << w << "\n";
    }
};

int main()
{
    char na[100];
    int h, ra, ba;
    cout << "Enter Name : ";
    cin >> na;
    cout << "Enter Basic pay : ";
    cin >> ba;
    cout << "Enter Hours worked : ";
    cin >> h;
    cout << "Enter Rate : ";
    cin >> ra;
    wages w(na, ba, h, ra);
    w.dplay();
    return 0;
}