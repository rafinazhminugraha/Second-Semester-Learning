#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string arrayPola[5][9] = 
    {
        {"  ","  ","* ","* ","  ","  ","* ","  ","* "},
        {"  ","* ","  ","  ","  ","  ","  ","  ","* "},
        {"* ","* ","* ","* ","* ","* ","* ","* ","* "},
        {"  ","* ","  ","  ","  ","  ","* ","  ","* "},
        {"  ","  ","* ","* ","  ","  ","* ","  ","* "}
    };

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << arrayPola[i][j];
            if(j == 8)
            {
                cout << "\n";
            }
        }
    }
    return 0;
}