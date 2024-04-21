#include <iostream>
using namespace std;

struct MAHASISWA
{
    string nama;
    string mataKuliah;
    int nilaiKehadiran;
    int nilaiTugas;
    int nilaiUts;
    int nilaiUas;
    string penentuanGrade;
};

int main()
{
    MAHASISWA rpl;

    double bobotKehadiran = 10.0/100;
    double bobotTugas = 20.0/100;
    double bobotUts = 30.0/100;
    double bobotUas = 40.0/100;
    int banyakNilai = 4;

    int batasanGradeA = 92;
    int batasanGradeB = 86;
    int batasanGradeC = 79;
    int batasanGradeD = 72;

    cout << "====== Menhitung Nilai Akhir Mahasiswa ======";

    cout << "\nNama mahasiswa   : "; getline(cin, rpl.nama);
    cout << "Mata Kuliah      : "; cin >> rpl.mataKuliah;
    cout << "Nilai Kehadiran  : "; cin >> rpl.nilaiKehadiran;
    cout << "Nilai Tugas      : "; cin >> rpl.nilaiTugas;
    cout << "Nilai UTS        : "; cin >> rpl.nilaiUts;
    cout << "Nilai UAS        : "; cin >> rpl.nilaiUas;

    int nilaiRerata = (rpl.nilaiKehadiran + rpl.nilaiTugas + rpl.nilaiUts + rpl.nilaiUas) / banyakNilai;

    rpl.nilaiKehadiran *= bobotKehadiran;
    rpl.nilaiTugas *= bobotTugas;
    rpl.nilaiUts *= bobotUts;
    rpl.nilaiUas *= bobotUas;

    int nilaiTotal = rpl.nilaiKehadiran + rpl.nilaiTugas + rpl.nilaiUts + rpl.nilaiUas;

    if (nilaiTotal >= batasanGradeA)
    {
        rpl.penentuanGrade = "A";
    }
    else if (nilaiTotal >= batasanGradeB)
    {
        rpl.penentuanGrade = "B";
    }
    else if (nilaiTotal >= batasanGradeC)
    {
        rpl.penentuanGrade = "C";
    }
    else if (nilaiTotal >= batasanGradeD)
    {
        rpl.penentuanGrade = "D";
    }
    else if (nilaiTotal < batasanGradeD)
    {
        rpl.penentuanGrade = "E";
    }
    else
    {
        rpl.penentuanGrade = "Masukkan nilai yang benar";
    }

    cout << "\n\nNilai Total            " << rpl.nama << " : " << nilaiTotal;
    cout << "\nNilai Rerata           " << rpl.nama << " : " << nilaiRerata;
    cout << "\nNilai Akhir (grade)    " << rpl.nama << " : " << rpl.penentuanGrade;

    cout << "\n======================================+======";

    return 0;
}