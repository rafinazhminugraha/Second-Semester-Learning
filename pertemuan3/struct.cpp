#include <iostream>

using namespace std;


struct CAR
{
    string judul;
    string penulis;
    bool member;
    int jumlahHalaman;
    int isbn;
};

CAR fiksi;
CAR nonFiksi;



int main() 
{
    fiksi.judul = "Bumi";
    fiksi.penulis = "rafi nazhmi";
    fiksi.member = true;
    fiksi.jumlahHalaman = 100;
    fiksi.isbn = 123456;

    cout << "Judul buku         : " << fiksi.judul << "\n";
    cout << "Penulis buku       : " << fiksi.penulis << "\n";
    cout << "Member buku        : " << fiksi.member << "\n";
    cout << "jumlahHalaman buku : " << fiksi.jumlahHalaman << "\n";
    cout << "Isbn buku          : " << fiksi.isbn << "\n"; 

}        