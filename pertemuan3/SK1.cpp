#include <iostream>
using namespace std;


struct MATA_KULIAH
{
    string namaMahaSiswa;
    string nim;
    int tugas1;
    int tugas2;
    int tugas3;
    int nilaiAkhir;
};


int main() 
{
    MATA_KULIAH inggris;

    cout << "\n------HITUNG NILAI AKHIR MAHASISWA MATKUL INGGRIS------\n";
    cout << "Nama Mahasiswa : "; getline(cin , inggris.namaMahaSiswa);
    cout << "NIm            : "; cin >> inggris.nim;
    cout << "Nilai Tugas 1  : "; cin >> inggris.tugas1;
    cout << "Nilai Tugas 2  : "; cin >> inggris.tugas2;
    cout << "Nilai Tugas 3  : "; cin >> inggris.tugas3;

    inggris.nilaiAkhir = (inggris.tugas1 + inggris.tugas2 + inggris.tugas3) / 3;

    cout << "\nNilai akhir mahasiswa matkul INGGRIS : " << inggris.nilaiAkhir << "\n";

    if(inggris.nilaiAkhir > 75)
    {
        cout << "Selamat " << inggris.namaMahaSiswa << " LULUS\n";
    }
    else
    {
        cout << "Maaf " << inggris.namaMahaSiswa << " Belum Lulus\n";
    }


}