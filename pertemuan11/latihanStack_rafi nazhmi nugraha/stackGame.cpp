#include <iostream>
using namespace std;

const int maks = 3;

struct STACK
{
    int top = 0;
    string data[maks];
};

STACK Tabung1, Tabung2, Tabung3, Tabung4;

bool tabungPenuh(STACK& tabung)
{
    if (tabung.top == maks)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

bool tabungKosong(STACK& tabung)
{
    if (tabung.top == 0)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

void tambahkanBola(STACK& tabung, string data)
{
    if (tabungPenuh(tabung))
    {
        cout << "Tabung sudah penuh";
    }
    else
    {
        tabung.data[tabung.top++] = data;
    }
}

void pindahkanBola(STACK& tabungAsal, STACK& tabungTujuan)
{
    if (tabungKosong(tabungAsal)) 
    {
        cout << "tidak bisa memindahkan, tabung asal kosong";
    }
    else if (tabungPenuh(tabungTujuan)) 
    {
        cout << "tidak bisa memindahkan, tabung tujuan penuh";
    }
    else 
    {
        tabungAsal.top--;
        tabungTujuan.data[tabungTujuan.top++] = tabungAsal.data[tabungAsal.top];
    }
}

void tampilkanDataTabung(STACK& tabung)
{
    if (tabungKosong(tabung))
    {
        cout << "Tabung kosong!\n";
    }
    else
    {
        for (int i = tabung.top - 1; i >= 0; i--)
        {
            cout << "- " << tabung.data[i] << "\n";
        }   
    }
}

int main() 
{
    tambahkanBola(Tabung1, "Biru");
    tambahkanBola(Tabung1, "Ungu");
    tambahkanBola(Tabung1, "Hijau");

    tambahkanBola(Tabung2, "Ungu");
    tambahkanBola(Tabung2, "Ungu");
    tambahkanBola(Tabung2, "Hijau");

    tambahkanBola(Tabung3, "Hijau");
    tambahkanBola(Tabung3, "Biru");
    tambahkanBola(Tabung3, "Biru");
    cout << endl;

    cout << "======================\n";
    cout << "Sebelum bola di susun: \n";
    cout << "======================\n\n";
    cout << "Tabung 1: " << endl;
    tampilkanDataTabung(Tabung1);
    cout << "Tabung 2: " << endl;
    tampilkanDataTabung(Tabung2);
    cout << "Tabung 3: " << endl;
    tampilkanDataTabung(Tabung3);
    cout << "Tabung 4: " << endl;
    tampilkanDataTabung(Tabung4);
    cout << endl;

    pindahkanBola(Tabung1, Tabung4);
    pindahkanBola(Tabung2, Tabung4);
    pindahkanBola(Tabung1, Tabung2);
    pindahkanBola(Tabung3, Tabung1);
    pindahkanBola(Tabung3, Tabung1);
    pindahkanBola(Tabung3, Tabung4);

    cout << endl;

    cout << "======================\n";
    cout << "Setelah bola di susun: \n";
    cout << "======================\n\n";
    cout << "Tabung 1: " << endl;
    tampilkanDataTabung(Tabung1);
    cout << "Tabung 2: " << endl;
    tampilkanDataTabung(Tabung2);
    cout << "Tabung 3: " << endl;
    tampilkanDataTabung(Tabung3);
    cout << "Tabung 4: " << endl;
    tampilkanDataTabung(Tabung4);

    return 0;
}