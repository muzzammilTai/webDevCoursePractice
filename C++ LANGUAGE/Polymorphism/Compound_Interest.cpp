#include <iostream>
using namespace std;

class compound
{
    double p, r;
    int t;

public:
    double CI, sum = 1;
    int i;
    compound() {}

    void input()
    {
        cout << "Enter the Principal Amount : ";
        cin >> p;
        cout << "Enter the Rate : ";
        cin >> r;
        cout << "Enter the Time : ";
        cin >> t;
    }

    double findInterest()
    {
        for (i = 0; i < t; i++)
        {
            sum = sum * (1 + (r / 100));
        }
        CI = p * sum - p;
        return CI;
    }

    void printData()
    {
        cout << "Principal Amount : " << p << "\nRate : " << r << "\nTime : " << t << "\nCompound Interest : " << CI << "\n";
    }
};

int main()
{
    compound user;
    user.input();
    user.findInterest();
    user.printData();
}