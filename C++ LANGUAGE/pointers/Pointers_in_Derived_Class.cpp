#include <iostream>
using namespace std;
class BasicClass
{
public:
    int b;
    void display()
    {
        cout << "\nDisplay Function of BASE Class .";
        cout << "\nb = " << b;
    }
};

class DerivedClass : public BasicClass
{
public:
    int d;
    void display()
    {
        cout << "\nDisplay Function of DERIVED Class .";
        cout << "\nd = " << d << "\nb = " << b;
    }
};

int main()
{
    BasicClass base;
    BasicClass *bptr; // creating pointer object of BASIC Class.
    bptr = &base;     // base address asssigned  to pointer of basic class.

    bptr->b = 100;   // assign value to variable b via bptr.
    bptr->display(); // calling display function of basic class.

    DerivedClass derived;
    bptr = &derived; // derived address assigned to pointer of base class.
    bptr->b = 200;   // assign value to variable b via bptr.
    bptr->display(); // calling display function of basic class.

    DerivedClass *dptr; // creating pointer object of DERIVED Class.
    dptr = &derived;    // derived address assigned to pointer of DERIVED class.
    dptr->d = 300;      // assign value to variable d via dptr.
    dptr->b = 400;
    dptr->display();
    return 0;
}