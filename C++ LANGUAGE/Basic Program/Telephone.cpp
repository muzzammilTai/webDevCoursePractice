#include <iostream>
using namespace std;
class Telephone
{
    int prv, pre, call;
    char name[100];
    double amt, total;

public:
    void input()
    {
        cout << "Enter the Previous Reading : ";
        cin >> prv;
        cout << "Enter the Present Reading : ";
        cin >> pre;
        cout << "Enter the Name of Customer : ";
        cin >> name;
    }
    void cal()
    {
        call = pre - prv;
        cout << "Total Calls made : " << call << "\n";
        if (call <= 100)
        {
            amt = 0;
        }
        else if (call > 100 && call <= 200)
        {
            amt = call * 0.90;
        }
        else if (call > 200 && call <= 400)
        {
            amt = call * 0.80;
        }
        else if (call > 400)
        {
            amt = call * 0.70;
        }
        total = 180 + amt;
    }

    void display()
    {
        cout << "\nName : " << name << "\nCalls made : " << call << "\nAmount to be Paid : " << total << "\n";
    }
};
int main()
{

    Telephone user;
    user.input();
    user.cal();
    user.display();
    return 0;
}