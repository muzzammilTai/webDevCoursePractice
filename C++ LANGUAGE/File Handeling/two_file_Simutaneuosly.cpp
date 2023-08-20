// Reading two file simutaneously
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main()
{
    char line[80];
    int i;
    ifstream fin1, fin2; // create two input streams
    fin1.open("country.txt");
    fin2.open("capital.txt");
    for (i = 1; i <= 10; i++)
    {
        if (fin1.eof() != 0)
        {
            cout << "Exit from country..\n";
            exit(1);
        }
        fin1.getline(line, 30);
        cout << "capital of " << line;
        if (fin2.eof() != 0)
        {
            cout << "\nExit from capital..\n";
            exit(1);
        }
        fin2.getline(line, 20);
        cout << " - " << line << "\n";
    }
    return 0;
}