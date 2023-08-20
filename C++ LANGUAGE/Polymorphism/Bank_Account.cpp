#include <iostream>
#include <stdlib.h>
using namespace std;
class bank
{
    char account_type[30], name[30];
    int account_no, balance, w, d;

public:
    void getdata()
    {
        cout << "Enter Account Number : ";
        cin >> account_no;
        cout << "Enter Type of Account : ";
        cin >> account_type;
        cout << "Enter Account Holder's Name : ";
        cin >> name;
        cout << "Enter Balance amount in the account : ";
        cin >> balance;
    }
    void deposit()
    {
        cout << "Enter Deposit Amount : ";
        cin >> d;
        balance = balance + d;
    }
    void withdrawl()
    {
        cout << "\nBalance in the Account : " << balance;
        cout << "\nEnter withrawl amount : ";
        cin >> w;
        balance = balance - w;
        cout << "\nBalance in the Account : " << balance;
    }
    void details()
    {
        cout << "\nAccount Holder Name : " << name << "\nBalance : " << balance << "\n";
    }
};

int main()
{
    bank user;
    int c;
    do
    {
        cout << "\n1.Enter Details\n2.Deposit\n3.Withdrawl\n4.Account Details\n5.Exit\nEnter your Choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            user.getdata();
            break;
        case 2:
            user.deposit();
            break;
        case 3:
            user.withdrawl();
            break;
        case 4:
            user.details();
            break;
        case 5:
            exit(0);
        }
    }
    while (c != 5);

        return 0;
}