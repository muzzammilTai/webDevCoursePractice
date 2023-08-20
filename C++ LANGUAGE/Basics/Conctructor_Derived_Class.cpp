/* Constructor in Derived Class Example */
#include <iostream>
using namespace std;
class alpha
{
    int x;

public:
    alpha(int i)
    {
        x = i;
    }
    void show_alpha()
    {
        cout << "Value of X : " << x << "\n";
    }
};

class beta
{
    int y;

public:
    beta(int j)
    {
        y = j;
    }
    void show_beta()
    {
        cout << "Value of Y : " << y << "\n";
    }
};

class gamma : public alpha, public beta
{
    int p, q;

public:
    gamma(int a, int b, int c, int d) : alpha(a), beta(b) // Deriving Constructor.
    {
        p = c;
        q = d;
    }
    void show_gamma()
    {
        show_alpha();
        show_beta();
        cout << "Value of P : " << p << "\nValue of Q : " << q << "\n";
    }
};

int main()
{
    int a, b, c, d;
    cout << "Enter the Values of a, b, c, and d : ";
    cin >> a >> b >> c >> d;
    gamma g(a, b, c, d);
    g.show_gamma();

    return 0;
}