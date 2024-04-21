#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    
    int num; cout << "masukkan angka = "; cin >> num;
    int *pnum; 
    pnum = &num;
    // *pnum = num;

    // cout << "nilai dari angka yang kamu masukkan adalah = " << num << "\n";
    cout << "nilai dari angka yang kamu masukkan adalah = " << *pnum << "\n";
    cout << "alamat dari angka yang kamu masukkan adalah = " << pnum << "\n";

    // *pnum = num;
    
    // cout << "nilai dari angka yang kamu masukkan adalah = " << *pnum << "\n";
    return 0;
}
