#include <iostream>
using namespace std;
class item
{
    int code;
    float price;

public:
    void getdata(int c, float p)
    {
        code = c;
        price = p;
    }
    void showData()
    {
        cout << "CODE : " << code << "\nPRICE : " << price;
    }
};

int main()
{
    item *p = new item[20];
    item *d = p;
    int x, i, n;
    float y;
    cout << "Enter the value of n : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Input code and Price for Item " << i + 1 << " : ";
        cin >> x >> y;  
        p->getdata(x, y);
        p++;
    }
    for (i = 0; i < n; i++)
    {
        cout << "\nItem " << i + 1 << "\n";
        d->showData();
        d++;
    }
    return 0;
}