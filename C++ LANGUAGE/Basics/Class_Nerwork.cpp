#include <iostream>
using namespace std;
class person
{
protected:
    char n[100];
    int c;

public:
    void input()
    {
        cout << "Enter the Name and Code of the Person : ";
        cin >> n >> c;
    }
    void output()
    {
        cout << "\nName : " << n << "\ncode : " << c << "\n";
    }
};

class account : virtual public person
{
protected:
    float pay;

public:
    void payment()
    {
        cout << "Enter Pay Amount : ";
        cin >> pay;
    }
    void dis_pay()
    {
        cout << "Pay : " << pay << "\n";
    }
};

class admin : public virtual person
{
protected:
    char exp[100];

public:
    void experience()
    {
        cout << "Enter Person's Experience : ";
        cin >> exp;
    }
    void dis_exp()
    {
        cout << "Experience : " << exp << "\n";
    }
};

class master : public account, public admin
{
public:
    void display()
    {
        input();
        payment();
        experience();
        output();
        dis_pay();
        dis_exp();
    }
};

int main()
{
    master M;
    M.display();
}