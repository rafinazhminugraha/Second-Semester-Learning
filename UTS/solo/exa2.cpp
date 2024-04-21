#include <iostream>
using namespace std;

int main()
{
    int choice = 2;
    do
    {
        cout << "[1] masuk\n";
        cout << "[2] masuk\n";
        cout << "[3] masuk\n";

        cout << "> "; cin >> choice;

        if (choice < 1 && choice >3)
        {
            cout << "invalid input";
        }
    }while(choice < 1 || choice >3);
    
    if (choice == 1)
    {
        cout << "ini adalah pilihan 1";
    }
    else if (choice == 2)
    {
        cout << "ini adalah pilihan 2";
    }
    else if (choice == 3)
    {
        cout << "Ini adalah pilihan 3";
    }
    
    
    return 0;
}
