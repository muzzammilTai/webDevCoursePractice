#include <iostream>
#include <stdlib.h>
using namespace std;
class account
{
protected:
    char name[100];
    long acct_no;

public:
    void getdata()
    {
        cout << "Enter your Account Number : ";
        cin >> acct_no;
        cout << "Enter Account holder's name : ";
        cin >> name;
    }
};

// Current Account.
class cur_acct : public account
{
protected:
    int c;
    double deposit, withdrawl, balance = 0, penalty;

public:
    int I, f;
    void input_cur()
    {

        do
        {
            cout << "\n\nchoose from below :\n1.DEPOSIT\n2.WITHDRAW\n3.CHECK BALANCE\n4.SERVICE CHARGES / PENALTY\n5.EXIT\n\nEnter your Choice : ";
            cin >> c;
            switch (c)
            {
            case 1:
                cout << "\nEnter Deposit Amount : ";
                cin >> deposit;
                balance = balance + deposit;
                break;

            case 2:
                cout << "\nChoose withdrawl Format :\n1.Reciept\n2.Cheque book\nEnter Your Choice : ";
                cin >> f;
                if (f == 1)
                {
                    cout << "\nEnter Withdrawl Amount : ";
                    cin >> withdrawl;
                    balance = balance - withdrawl;
                }
                else if (f == 2)
                {
                    cout << "\nEnter Withdrawl Amount : ";
                    cin >> withdrawl;
                    balance = balance - withdrawl;
                }

                break;
            case 3:
                cout << "\nYour Current Balance : " << balance << "\n";
                cout << "\nAccount Number : " << acct_no << "\nName : " << name << "\nAccount Balance : " << balance << "\n";
                break;
            case 4:
                if (balance < 1000)
                {
                    penalty = 500;
                }
                else
                {
                    penalty = 0;
                }
                cout << "Service Charge : " << penalty << "\n";
                break;
            case 5:
                exit(0);
                break;
            }
        } while (c != 5);
        if (balance < 1000)
        {
            penalty = 500;
        }
        else
        {
            penalty = 0;
        }
        cout << "Service Charge : " << penalty << "\n";
    }
};

// Savings Account.
class savings_acct : public account
{
protected:
    int c;
    double deposit, withdrawl, balance = 0;

public:
    int I, f;
    void input_savings()
    {
        do
        {
            cout << "\n\nchoose from below :\n1.DEPOSIT\n2.WITHDRAW\n3.CHECK BALANCE\n4.EXIT\n\nEnter your Choice : ";
            cin >> c;
            switch (c)
            {
            case 1:
                cout << "\nEnter Deposit Amount : ";
                cin >> deposit;
                balance = balance + deposit;
                break;

            case 2:
                cout << "\nChoose withdrawl Format :\n1.Reciept\n2.Cheque book\nEnter Your Choice : ";
                cin >> f;
                if (f == 1)
                {
                    cout << "\nEnter Withdrawl Amount : ";
                    cin >> withdrawl;
                    balance = balance - withdrawl;
                }
                else if (f == 2)
                {
                    cout << "Sorry, Savings Account dose not provides Cheque book facility for withdrawl.\n ";
                }
                break;
            case 3:
                cout << "\nYour Current Balance : " << balance << "\n";
                cout << "\nAccount Number : " << acct_no << "\nName : " << name << "\nAccount Balance : " << balance << "\n";
                break;
            case 4:
                exit(0);
                break;
            }
        } while (c != 4);
    }
    void intrest()
    {
        I = balance * 0.8;
        cout << "Compound Intrest : " << I << "\n";
    }
};

int main()
{
    cur_acct c;
    savings_acct s;
    int type, choice;
    c.getdata();
    cout << "Choose Your Account Type from Below :\n1.CURRENT ACCOUNT\n2.SAVINGS ACCOUNT\n\nEnter your choice : ";
    cin >> choice;

    if (choice == 1)
    {
        c.input_cur();
    }
    else
    {
        s.input_savings();
        s.intrest();
    }
    return 0;
}