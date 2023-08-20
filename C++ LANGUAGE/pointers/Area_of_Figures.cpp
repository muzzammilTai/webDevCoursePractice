#include <iostream>
using namespace std;
class shape
{
protected:
    double a, b;

public:
    void get_data()
    {
        cout << "Enter the Value of a and b : ";
        cin >> a >> b;
    }
    virtual void display_area()
    {
    }
};

class rectangle : public shape
{
public:
    double area;
    void display_area()
    {
        area = a * b;
        cout << "\nArea of Rectangle : " << area << "\n";
    }
};

class triangle : public shape
{
public:
    double area;
    void display_area()
    {
        area = (a * b) / 2;
        cout << "\nArea of Triangle : " << area << "\n";
    }
};

int main()
{
    shape *s;
    shape *sptr;
    rectangle r;
    triangle t;

    s = &r;
    s->get_data();
    s->display_area();

    sptr = &t;
    sptr->get_data();
    sptr->display_area();
    return 0;
}