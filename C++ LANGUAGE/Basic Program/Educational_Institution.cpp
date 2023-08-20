 #include <iostream>
using namespace std;

class Staff
{
protected:
    char name[100];

public:
    void Code_name()
    {
        cout << "Enter Name : ";
        cin >> name;
    }
};

class teacher : public Staff
{
public:
    char sub[100];
    void subject()
    {
        cout << "Enter Subject Publication : ";
        cin >> sub;
        cout << "\nName : " << name << "\nSubject Publication : " << sub;
    }
};

class typist : public Staff
{
public:
    int spd;
    void speed()
    {
        cout << "Enter Typist's Speed : ";
        cin >> spd;
    }
};

class casual : public typist
{
public:
    int dw;
    void daily_wages()
    {
        cout << "Enter Daily Wages : ";
        cin >> dw;
        cout << "\nName : " << name << "\nSpeed : " << spd << "\nDaily Wages : " << dw << "\n";
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

class Officer : public Staff
{
public:
    int g;
    void grade()
    {
        cout << "Enter Officer's Grade : ";
        cin >> g;
        cout << "\nName : " << name << "\nOfficers's Grade : " << g;
    }
};
int main()
{
    Staff s;
    int choice, ch;
    teacher t;
    typist ty;
    Officer o;
    regular r;
    casual c;
    cout << "\nChoose Staff Type from below : \n1.TEACHER\n2.TYPIST\n3.OFFICER\nChoice : ";
    cin >> choice;
    if (choice == 1)
    {
        t.Code_name();
        t.subject();
    }
    else if (choice == 2)
    {
        cout << "Choose Typist : \n1.Regular\n2.Casual\nchoice : ";
        cin >> ch;
        if (ch == 1)
        {
            r.Code_name();
            r.speed();
            r.display();
        }
        else
        {
            c.Code_name();
            c.speed();
            c.daily_wages();
        } 
    }
    else if (choice == 3)
    {
        o.Code_name();
        o.grade();
    }
    return 0;
}