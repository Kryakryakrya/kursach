#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    const char* path = "file.bin";
    vector<int> marked;
    cout << "Welcome!" << endl;
    while (true)
    {
        cout << "Select 1 to add the new data\n";
        cout << "Select 2 to show all\n";
        cout << "Select 3 to show the data by the number\n";
        cout << "Select 4 to choise data for delete\n";
        cout << "Select 5 to clear file from selected data\n";
        cout << "Select 6 to edit data\n";
        cout << "Select 7 to make a result\n";
        cout << "Select 0 - zachita\n";
        cout << "Select -1 to exit" << endl;
        int a;
        cin >> a;
        if (a == 1)
            mywrite(path);
        else if (a == 2)
            readall(path);
        else if (a == 3)
        {
            cout << "Input order number of line" << endl;
            int num;
            cin >> num;
            readnumber(path, num);
        }
        else if (a == 4)
            metka(marked);
        else if (a == 5)
            del(marked, path);
        else if (a == 6)
            change(path);
        else if (a == 7)
            result(path);
        else if (a == 0)
            zachita(path);
        else 
            break;
    }
    return 0;
}
