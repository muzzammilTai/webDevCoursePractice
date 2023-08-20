#include <iostream>
using namespace std;

class items
{
    int itemCode[30], a, i, count;
    float itemPrice[30], sum = 0;

public:
    void checkCount()
    {
        count = 0;
    }
    void getItem()
    { 
        cout << "Enter item code : ";
        cin >> itemCode[count];
        cout << "Enter item price : ";
        cin >> itemPrice[count];
        count++;
    }
    void displaySum()
    {
        sum = 0;
        for (i = 0; i < count; i++)
        {
            sum = sum + itemPrice[i];
        }
        cout << "\nTotal Value : " << sum << "\n";
    }
    void removeItem()
    {
        cout << "Enter item code : ";
        cin >> a;
        for (i = 0; i < count; i++)
        {
            if (itemCode[i] == a)
            {
                itemPrice[i] = 0;
            }
        }
    }
    void displayItem()
    {
        for (i = 0; i < count; i++)
        {
            cout << "Item Code : " << itemCode[i] << "\nItem Price : " << itemPrice[i] << "\n\n";
        }
    }
};

int main()
{
    items order;
    order.checkCount();
    int x;
    do
    {
        cout << "\nYou can Do Following:\nEnter Appropriate number : ";
        cout << "\n1.Add an Item.\n2.Display Total Value.\n3.Delete an Item.\n4.Display all Item.\n5.Quit\nWhats your option : ";
        cin >> x;
        switch (x)
        {
        case 1:
            order.getItem();
            break;
        case 2:
            order.displaySum();
            break;
        case 3:
            order.removeItem();
            break;
        case 4:
            order.displayItem();
            break;
        default:
            cout << "\nError in input : try again..\n";
            break;
        }
    } while (x != 5);
    return 0;
}