/* Static Member Function Example */

#include <iostream>
using namespace std;
class test
{
    int code;
    static int count; // static number variable.

public:
    void setCode()
    {
        code = count++; // count = count + 1.
    }
    void shoeCode()
    {
        cout << "Object Number : " << code << "\n";
    }
    static void showCount() // static member function.
    {
        cout << "Count : " << count << "\n";
    }
};

int test ::count; // ddefination of static data member variable.
int main()
{
    test t1, t2, t3;
    t1.setCode();
    t2.setCode();
    t3.setCode();
    test::showCount(); // accessing static function.

    // test t3;
    // test.setcode();

    // test::showCount();

    t1.shoeCode();
    t2.shoeCode();
    t3.shoeCode();
    return 0;
}