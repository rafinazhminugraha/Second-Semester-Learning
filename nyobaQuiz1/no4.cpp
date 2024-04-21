#include <iostream>
#include <cstring>
using namespace std;

int hitungJumlahKata(int jumlahHuruf, char Pkalimat[]);

int main()
{
    char kalimat[1000]; char *Pkalimat = kalimat;
    cout << "ketik suatu kalimat atau kata : "; cin.getline(kalimat,1000);

    int jumlahHuruf = strlen(kalimat);

    int jumlahKata = hitungJumlahKata(jumlahHuruf, Pkalimat);
    cout << "Jumlah kata yang di inputkan adalah = " << jumlahKata;
}

int hitungJumlahKata(int jumlahHuruf, char Pkalimat[])
{
    int jumlahKata = 1;

    for (int i = 0; i < jumlahHuruf; i++)
    {
        if (Pkalimat[i] == ' ')
        {
            jumlahKata += 1;
        }
        
    }
    int hurufTerakhir = jumlahHuruf - 1;
    if (Pkalimat[hurufTerakhir] == ' ')
    {
        jumlahKata -= 1;
    }
    
    return jumlahKata;
}
