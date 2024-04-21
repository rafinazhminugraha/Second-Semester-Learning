#include <iostream>
#include <cstring>
using namespace std;

int jumlahKata(int panjangKata, char kata[]);
void swap(int panjangKata, char Pkata[]);

int main()
{
    char kata[60];
    char *Pkata = kata;
    cout << "masukkan suatu kata        : "; cin.getline(kata, 100);
    
    int panjangKata = strlen(kata);
    cout << panjangKata << endl;

    cout << "Jumlah Kata Yang Di Input  : " << jumlahKata(panjangKata, Pkata) << "\n";

    swap(panjangKata, Pkata);

    return 0;
}

void swap(int panjangKata, char Pkata[])
{
    for(int i = 0; i < panjangKata / 2; i++)
    {
        swap(Pkata[i], Pkata[panjangKata-i-1]);
    }

    cout << "Kata yang sudah di balik   : " << '"' << Pkata << '"';
}

int jumlahKata(int panjangKata, char kata[])
{
    int jumlahKata = 1;

    for(int i = 0; i < panjangKata; i++)
    {
        if(kata[i] == ' ')
        {
            jumlahKata += 1;
        }
    }
    if(panjangKata < 1)
    {
        jumlahKata = 0;
    }
    int kataTerakhir = panjangKata - 1;
    if(kata[kataTerakhir] == ' ')
    {
        jumlahKata -= 1;
    }
    return jumlahKata;
}