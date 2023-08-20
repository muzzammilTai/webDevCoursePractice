#include <iostream>
using namespace std;
class person
{
protected:
    char name[100];
    int cd;

public:
    void input_data()
    {
        cout << "Enter the Name and Code : ";
        cin >> name >> cd;
    }

    void getdata()
    {
        cout << "Code : " << cd << "\nName : " << name;
    }
};

class account : public person
{
protected:
    int p;

public:
    void pay()
    {
        cout << "Enter Pay Amount : ";
        cin >> p;
    }

    void amount()
    {
        cout << "\nPay : " << p;
    }
};

class admin : public person
{
protected:
    char E[100];

public:
    void exp()
    {
        cout << "Enter the Experience : ";
        cin >> E;
    }

    void display()
    {
        cout << "\nExperince : " << E;
    }
};

class master : public admin, public account
{
public:
    void update()
    {
        getdata();
        amount();
        display();
    }
};

int main()
{
    master M;

    M.input_data();
    M.pay();
    M.exp();
    M.update();
    return 0;
}