#include <iostream>
using namespace std;

int main()
{
    int x; cout << "Masukan nilai x = "; cin >> x;

    int *p;
    p =&x;

    cout << "Output 1\n";
    cout << "Nilai x = " << x << "\n";
    cout << "alamat x = " << p << "\n";

    cout << "\nMasukkan nilai x = "; cin >> x;
    // *p = x;

    cout << "Output 2\n";
    cout << "Nilai x = " << *p << "\n";
    cout << "alamat x = " << p << "\n";


    return 0;
}
