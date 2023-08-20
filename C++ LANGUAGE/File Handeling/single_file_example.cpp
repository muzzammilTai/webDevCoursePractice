// working with single file
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream outf("item.txt"); // connect item.txt file with outf
    float cost;
    char name[20];
    cout << "Enter Name : ";
    cin >> name; // get Name from keyboard

    outf << name << "\n"; // write name to file item.txt

    cout << "Enter item cost : ";
    cin >> cost; // get cost from keyboard

    outf << cost << "\n"; // write cost to file item.txt

    outf.close(); // disconnect item.txt file from outf

    ifstream inf("item.txt"); // connect item.txt file to inf
    inf >> name;              // read name from file item.txt
    inf >> cost;              // read cost from file item.txt

    cout << "\n";
    cout << "Item Name : " << name << "\nItem Cost : " << cost;
    inf.close(); // Disconnect item.txt from inf

    return 0;
}