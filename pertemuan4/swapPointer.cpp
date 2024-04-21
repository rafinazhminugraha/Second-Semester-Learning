#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int x; cout << "masukkan nilai x = "; cin >> x;
    int y; cout << "masukkan nilai y = "; cin >> y;
    cout << "\nNilai dari x = " << x;
    cout << "\nNilai dari y = " << y;
    cout << "\nAlamat nilai dari x = " << &x;
    cout << "\nAlamat nilai dari y = " << &y;

    swap(y, x);

    cout << "\nNilai dari x = " << x;
    cout << "\nNilai dari y = " << y;
    cout << "\nAlamat nilai dari x = " << &x;
    cout << "\nAlamat nilai dari y = " << &y;
    
    return 0;
}
