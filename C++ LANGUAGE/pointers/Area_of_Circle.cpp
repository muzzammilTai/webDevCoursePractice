#include <iostream>
using namespace std;
class shape
{
protected:
    double a, b;

public:
    void get_data()
    {
        cout << "\nEnter the Value of a and b : ";
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
        cout << "Area of Rectangle : " << area << "\n";
    }
};

class triangle : public shape
{
public:
    double area;
    void display_area()
    {
        area = (a * b) / 2;
        cout << "Area of Triangle : " << area << "\n";
    }
};

class circle : public shape
{
public:
    double area;
    void display_area()
    {
        area = 3.14 * a * a;
        cout << "Area of Circle : " << area << "\n";
    }
};

int main()
{
    shape *s[3];
    rectangle r;
    triangle t;
    circle c;

    s[0] = &r;
    s[0]->get_data();
    s[0]->display_area();

    s[1] = &t;
    s[1]->get_data();
    s[1]->display_area();

    s[2] = &c;
    s[2]->get_data();
    s[2]->display_area();
    return 0;
}