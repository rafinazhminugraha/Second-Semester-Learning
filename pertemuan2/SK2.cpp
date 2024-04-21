// TUGAS INDIVIDU 2

#include <iostream>

using namespace std;

int main()
{
    int nilai[10] = {97,90,68,75,80,89,62,45,99,71};
    double total = 0;
    int panjangArray = sizeof(nilai)/sizeof(int);

    for(int i = 0; i < 10; i++)
    {
        total += nilai[i];
    }

    double rerata = total / panjangArray;

    cout << "rerata dari nilai dalam array adalah = " << rerata;
}