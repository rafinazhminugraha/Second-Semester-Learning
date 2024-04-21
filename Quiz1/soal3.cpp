
// contoh ini saya buat berdasarkan studi kasus  yang sudah saya sederhanakan dari modul perkuliahan pertemuan pointer dan swap
// dan penggunaanya sudah saya sederhanakan

#include <iostream>
#include <cstring>
using namespace std;

// ini untuk mengisiasi fungsi untuk menghitung kata di bawah agar kode terlihat lebih rapih
int hitungJumlahKata(int jumlahHuruf, char Pkalimat[]);

// ini adalah fungsi utama program
int main()
{
    // ini adalah variabel untuk menyimpan input kalimat nya
    char kalimat[1000]; 

    // ini untuk mendeklarasikan si variabel kalimat agar bisa di teack menggunakan pointer menggunakan *
    char *Pkalimat = kalimat;
    cout << "ketik suatu kalimat atau kata : "; cin.getline(kalimat,1000);

    // ini untuk mengetahui jumlah huruf yang di inputkan, untuk tau index dari setiap huruf
    int jumlahHuruf = strlen(kalimat);

    // ini untuk menghitung jumlah kata menggunakan fungsi yang sudah dibuat
    int jumlahKata = hitungJumlahKata(jumlahHuruf, Pkalimat);

    // ini untuk menampilkan output hasil akhir
    cout << "Jumlah kata yang di inputkan adalah = " << jumlahKata;
}

// ini adalah fungsi untuk menghitung jumlah kata
int hitungJumlahKata(int jumlahHuruf, char Pkalimat[])
{
    // ini untuk mengisiasikan jumlah kata yang di inputkan pasti setidaknya satu
    int jumlahKata = 1;

    // ini untuk meng tracking setiap index didalam variabel induk menggunakan pointer 
    for (int i = 0; i < jumlahHuruf; i++)
    {
        if (Pkalimat[i] == ' ')
        {
            jumlahKata += 1;
        }
        
    }

    // ini untuk mengetahui apakah huruf terakhir adalah huruf atau bukan, jika bukan maka jumlah kata akan dikurangi satu agar sesuai
    int hurufTerakhir = jumlahHuruf - 1;
    if (Pkalimat[hurufTerakhir] == ' ')
    {
        jumlahKata -= 1;
    }
    
    // ini untuk membalikkan hasil jumlah kata
    return jumlahKata;
}
