// working with multiple file
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int i, ncountry, ncapital;
    char country[20], capital[20];

    ofstream fout;            // create output stream
    fout.open("Country.txt"); // connect to file country.txt

    fout << "United States of America\n";
    fout << "United Kingdom\n";
    fout << "India";

    fout.close(); // disconnect country.txt

    fout.open("Capital.txt"); // connect to file Capital.txt

    fout << "Washington\n";
    fout << "London\n";
    fout << "New Delhi";

    fout.close(); // disconnect Capital.txt

    // Reading from files
    char line[100];
    ifstream fin;            // create input stream
    fin.open("Country.txt"); // connect to country
    cout << "Content of country file\n";
    while (fin)
    {
        fin.getline(line, 30); // read a line
        cout << line << "\n";
    }
    fin.close(); // disconnect country.txt

    fin.open("Capital.txt"); // connect to Capital
    cout << "Contents of Capital file\n";
    while (fin)
    {
        fin.getline(line, 30); // read a line
        cout << line << "\n";
    }
    fin.close(); // disconnect Capital.txt

    return 0;
}