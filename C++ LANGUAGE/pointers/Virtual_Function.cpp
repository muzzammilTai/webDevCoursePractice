#include <iostream>
using namespace std;
class Base
{
public:
    void display()
    {
        cout << "\nDisplay Function of Base class : ";
    }
    virtual void show()
    {
        cout << "\nShow Function of Base class : ";
    }
};

class Derived : public Base
{
public:
    void display()
    {
        cout << "\nDisplay Function of Derived class : ";
    }
    void show()
    {
        cout << "\nShow Function of Derived class : ";
    }
};

int main()
{
    Base B;     // creating object of base class.
    Base *bptr; // creating pointer object of base class.
    Derived D;  // creating object of Derived class.

    cout << "\nbptr points to base class : ";
    bptr = &B;
    bptr->display(); // calls the display function of the base class.
    bptr->show();    // calls the show function of base class.

    cout << "\nbptr points to Derived class : ";
    bptr = &D;
    bptr->display(); // calls the display function of the derived class.
    bptr->show();    // calls the show function of derived class.

    return 0;
}