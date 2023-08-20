#include <iostream>
#include <stdlib.h>
using namespace std;
class bank
{
    char account_type[30][30], name[30][30];
    int count, i, account_no[30], balance[30], w[30], d[30];

public:
    void checkCount()
    {
        count = 0;
    }
    void getdata()
    {
        cout << "Enter Account Number : ";
        cin >> account_no[count];
        cout << "Enter Type of Account : ";
        cin >> account_type[count];
        cout << "Enter Account Holder's Name : ";
        cin >> name[count];
        cout << "Enter Balance amount in the account : ";
        cin >> balance[count];
        count++;
    }
    void deposit()
    {
        for (i = 0; i < count; i++)
        {
            cout << "Enter Deposit Amount No." << i << " : ";
            cin >> d[i];
            balance[i] = balance[i] + d[i];
        }
    }
    void withdrawl()
    {
        for (i = 0; i < count; i++)
        {
            cout << "\nBalance in the Account No." << i << " : " << balance[i];
            cout << "\nEnter withrawl amount No." << i << " : ";
            cin >> w[i];
            balance[i] = balance[i] - w[i];
            cout << "\n\nBalance in the Account No." << i << " : " << balance[i];
        }
    }
    void details()
    {
        for (i = 0; i < count; i++)
        {
            cout << "\nAccount Holder Name : " << name[i] << "\nBalance : " << balance[i] << "\n";
        }
    }
};

int main()
{
    bank user;
    user.checkCount();
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
    } while (c != 5);

    return 0;
}