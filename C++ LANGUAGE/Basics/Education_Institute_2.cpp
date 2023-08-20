#include <iostream>
#include <stdlib.h>
using namespace std;
class staff
{
public:
    char name[100];
    int c;

public:
    void code_name()
    {
        cout << "Enter Staff Name and code : ";
        cin >> name >> c;
    }
};

class education
{
public:
    char HQ[100], HPQ[100];
    void Qualification()
    {
        cout << "Enter Highest Qualifications : ";
        cin >> HQ;
        cout << "Enter Highest Professinal Qualifications : ";
        cin >> HPQ;
        cout << "Higest Qualification : " << HQ << "\nHigest Professional Qualification : " << HPQ << "\n";
    }
};
class teacher : public staff, public education
{
public:
    char sub[100], publication[20];
    void subject()
    {
        cout << "Enter Subject and Publication : ";
        cin >> sub >> publication;
        cout << "\nName : " << name << "\nSubject : " << sub << "\n";
    }
};

class typist : public staff
{
public:
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

class officer : public staff, public education
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
    education e;
    regular r;

    int c;

    int sp;
    cout << "Choose from Below :\n1.TEACHER\n2.TYPIST\n3.OFFICER\n";
    cin >> c;
    if (c == 1)
    {
        t.code_name();
        t.subject();
        t.Qualification();
    }
    else if (c == 2)
    {
        cout << "Choose Speed :\n1.REGULAR\n2.CASUAL\nChoice : ";
        cin >> sp;
        if (sp == 2)
        {
            cas.code_name();
            cas.speed();
            cas.wages();
        }
        else
        {
            r.code_name();
            r.speed();
            //cout << "NO DATA\n";
            r.display();
        }
    }
    else if (c == 3)
    {
        o.code_name();
        o.grade();
        o.Qualification();
    }
    return 0;
}