#include <iostream>
using namespace std;

struct MAHASISWA
{
    string namaMahasiswa;
    string NIM;
    int angkatan;
    string prodi;
    int nilai;
};

struct MATA_KULIAH
{
    MAHASISWA rpl;
    string kodeMatkul;
};



int main()
{
    MATA_KULIAH sda;
    MAHASISWA rpl;

    rpl.nilai = 90;

    cout << "Nama       : "; getline(cin, rpl.namaMahasiswa);
    cout << "NIM        : "; cin >> rpl.NIM;
    cout << "Angkatan   : "; cin >> rpl.angkatan;
    cout << "Prodi      : "; cin >> rpl.prodi;
    cout << "Kode Matkul: "; cin >> sda.kodeMatkul;

    MATA_KULIAH hirarki;
    hirarki.rpl.namaMahasiswa;



}