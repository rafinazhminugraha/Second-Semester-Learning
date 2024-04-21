#include <iostream>
#include <iomanip>
using namespace std;

struct FILM
{
    string costumer;
    int pesanTiket;
    double diskon;
    int jumlahTiket;
    double pembayaran;
};


int main()
{
    FILM gotg;

    double const hargaTiket = 50000;
    double diskon = 0.1;
    int bonusTiket = 0;
    gotg.diskon = 0;


    cout << "\n--------PEMESANAN TIKET FILM GOTG VOL.2--------\n";

    cout << "\nNama           : "; getline(cin, gotg.costumer);
    cout << "Berapa Tiket   : "; cin >> gotg.pesanTiket;

    gotg.pembayaran = hargaTiket * gotg.pesanTiket;

    if(gotg.pesanTiket < 1)
    {
        cout << "\n---------------INVOICE---------------\n";
        cout << "  The Guardians Of The Galaxy vol.2\n";
        cout << "             Rp. 50.000";
        cout << "\n-------------------------------------\n";
        cout << "\nAnda tidak memesan tiket apapun\n";
        return 0;
    }
    else if (gotg.pesanTiket < 5)
    {
        gotg.jumlahTiket = gotg.pesanTiket;
    }
    else if(gotg.pesanTiket > 4 && gotg.pesanTiket < 10)
    {
        gotg.diskon = gotg.pembayaran * diskon;
        gotg.pembayaran-=gotg.diskon;
        gotg.jumlahTiket = gotg.pesanTiket;
    }
    else if(gotg.pesanTiket > 9)
    {
        gotg.jumlahTiket = gotg.pesanTiket + 1;
        bonusTiket += 1;
    }

    cout << "\n---------------INVOICE---------------\n";
    cout << "  The Guardians Of The Galaxy vol.2\n";
    cout << "             Rp. 50.000";
    cout << "\n-------------------------------------\n";
    cout << "\nNama               : " << gotg.costumer << "\n";
    cout << "Total pesanan      : " << gotg.pesanTiket << "\n";
    cout << "Total bonus        : " << bonusTiket << "\n";
    cout << "Total diskon       : Rp." << gotg.diskon << "\n";
    cout << "Total tiket        : " << gotg.jumlahTiket << "\n";
    cout << "Total Pembayaran   : Rp." << fixed << setprecision(0) << gotg.pembayaran << "\n";
    
    cout << "\n------------------TERIMA KASIH------------------\n";
}