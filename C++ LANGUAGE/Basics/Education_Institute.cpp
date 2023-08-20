#include <iostream>
#include <stdlib.h>
using namespace std;
class staff
{
protected:
    char name[100];
    int c;

public:
    void code_name()
    {
        cout << "Enter Staff Name : ";
        cin >> name;
    }
};
class teacher : public staff
{
public:
    char sub[100];
    void subject()
    {
        cout << "Enter Subject Publication : ";
        cin >> sub;
        cout << "\nName : " << name << "\nSubject : " << sub << "\n";
    }
};

class typist : public staff
{
protected:
    int spd;

public:
    void speed()
    {
        cout << "Enter Speed : ";
        cin >> spd;
    }
};
class regular : public typist
{
public:
    void display()
    {
        cout << "\nName : " << name << "\nSpeed : " << spd << "\n";
    }
};
class causual : public typist
{
public:
    int daily_wages;
    void wages()
    {
        daily_wages = 200;
        cout << "\nName : " << name << "\nSpeed : " << spd << "\nDaily Wages : " << daily_wages << "\n";
    }
};
class officer : public staff
{
public:
    char g[100];
    void grade()
    {
        cout << "Enter Officer's Grade : ";
        cin >> g;
        cout << "\nName : " << name << "\nGrade : " << g << "\n";
    }
};

int main()
{
    staff s;
    teacher t;
    typist ty;
    officer o;
    causual cas;
    regular r;

    int c;

    int sp;
    cout << "Choose from Below :\n1.TEACHER\n2.TYPIST\n3.OFFICER\n";
    cin >> c;
    if (c == 1)
    {
        t.code_name();
        t.subject();
    }
    else if (c == 2)
    {
        cas.code_name();

        cout << "Choose Speed :\n1.REGULAR\n2.CASUAL\nChoice : ";
        cin >> sp;
        if (sp == 2)
        {
            cas.speed();
            cas.wages();
        }
        else
        {
            r.speed();
            r.display();
        }
    }
    else if (c == 3)
    {
        o.code_name();
        o.grade();
    }
    return 0;
}