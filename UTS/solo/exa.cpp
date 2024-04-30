#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

void printJudul() {
    cout << "\033[2J\033[1;1H";
    cout << "=============\n";
    cout << "     ATM     \n";
    cout << "=============\n";
}

struct Transaksi {
    string keterangan;
    int jumlah;
    time_t waktu;
};

struct Nasabah {
    string nama;
    vector<Transaksi> riwayatTransaksi;
    int pin;
    int nomorKartu;
    int saldo;
    Nasabah* prev;
    Nasabah* next;
};

int generateNomorKartu() {
    return rand() % 900 + 100;
}

bool isNamaTerdaftar(Nasabah* head, const string& nama) {
    Nasabah* temp = head;
    while (temp != nullptr) {
        if (temp->nama == nama) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

Nasabah* cariNasabah(Nasabah* head, int nomorKartu, int pin) {
    Nasabah* temp = head;
    while (temp != nullptr) {
        if (temp->nomorKartu == nomorKartu && temp->pin == pin) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

Nasabah* cariNasabahTransfer(Nasabah* head, int nomorKartu) {
    Nasabah* temp = head;
    while (temp != nullptr) {
        if (temp->nomorKartu == nomorKartu) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void menuProfile(Nasabah* nasabah) {
    while (true) {
        printJudul();
        cout << "Profile\n\n";

        cout << "Nama: " << nasabah->nama << endl;
        cout << "Nomor Kartu: " << nasabah->nomorKartu << endl;
        cout << "PIN: " << nasabah->pin << endl;

        cout << "\n[1] Edit Nama";
        cout << "\n[2] Edit PIN";
        cout << "\n[3] Kembali ke Menu Utama";
        cout << "\n\n> ";

        int opsi;
        cin >> opsi;

        switch (opsi) {
            case 1:
                cout << "Masukkan nama baru: ";
                cin.ignore();
                getline(cin, nasabah->nama);
                cout << "Nama berhasil diubah.\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
            case 2:
                cout << "Masukkan PIN baru: ";
                cin >> nasabah->pin;
                cout << "PIN berhasil diubah.\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
            case 3:
                return;
            default:
                cout << "Tolong input angka 1, 2, atau 3.\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
        }
    }
}

void cekSaldo(Nasabah* nasabah) {
    while (true) {
        printJudul();
        cout << "Sisa Saldo Anda: Rp." << nasabah->saldo << endl;

        cout << "\n[1] Kembali ke Menu Utama";

        int opsi;
        cout << "\n\n> ";
        cin >> opsi;

        switch (opsi) {
            case 1:
                return;
            default:
                cout << "Inputan Anda Salah\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
        }
    }
}

void rekamTransaksi(Nasabah* nasabah, const string& keterangan, int jumlah) {
    Transaksi transaksi;
    transaksi.keterangan = keterangan;
    transaksi.jumlah = jumlah;
    transaksi.waktu = time(nullptr); // Waktu saat ini
    nasabah->riwayatTransaksi.push_back(transaksi);
}

void menuTransfer(Nasabah* head, Nasabah* nasabah) {
    printJudul();
    cout << "Menu Transfer\n\n";

    int nomorKartuTujuan;
    cout << "Masukkan Nomor Kartu Tujuan: ";
    cin >> nomorKartuTujuan;

    Nasabah* tujuan = cariNasabahTransfer(head, nomorKartuTujuan);
    if (tujuan == nullptr) {
        cout << "Nomor Kartu tujuan tidak valid.\n";
        this_thread::sleep_for(chrono::seconds(1));
        return;
    }

    int jumlahTransfer;
    cout << "Masukkan Jumlah Transfer: Rp. ";
    cin >> jumlahTransfer;

    if (jumlahTransfer <= 0) {
        cout << "Jumlah transfer tidak valid.\n";
        this_thread::sleep_for(chrono::seconds(1));
        return;
    }

    if (nasabah->saldo < jumlahTransfer) {
        cout << "Saldo Anda tidak mencukupi untuk melakukan transfer ini.\n";
        this_thread::sleep_for(chrono::seconds(1));
        return;
    }

    nasabah->saldo -= jumlahTransfer;
    tujuan->saldo += jumlahTransfer;

    cout << "Transfer berhasil dilakukan.\n";
    cout << "Sisa saldo Anda: Rp. " << nasabah->saldo << endl;
    this_thread::sleep_for(chrono::seconds(1));

    // Merekam transaksi pada pengirim dan penerima
    rekamTransaksi(nasabah, "Transfer keluar ke " + tujuan->nama, jumlahTransfer);
    rekamTransaksi(tujuan, "Transfer masuk dari " + nasabah->nama, jumlahTransfer);
}

void tampilkanRiwayatTransaksi(Nasabah* nasabah) {
    printJudul();
    cout << "Riwayat Transaksi\n\n";

    if (nasabah->riwayatTransaksi.empty()) {
        cout << "Tidak ada transaksi.\n";
    } else {
        for (const Transaksi& transaksi : nasabah->riwayatTransaksi) {
            cout << "Waktu: " << ctime(&transaksi.waktu); // Konversi waktu ke string
            cout << "Keterangan: " << transaksi.keterangan << endl;
            cout << "Jumlah: Rp. " << transaksi.jumlah << endl;
            cout << "---------------------" << endl;
        }
    }

    cout << "\n[1] Kembali ke Menu Utama\n";
    cout << "\n\n> ";
    int opsi;
    cin >> opsi;
}

void menuSetortunai(Nasabah* head, Nasabah* nasabah) {
    printJudul();
    cout << "Menu Setor Tunai\n\n";

    int jumlahSetorTunai;
    cout << "Masukkan Jumlah Setor Tunai: Rp. ";
    cin >> jumlahSetorTunai;

    if (jumlahSetorTunai <= 0) {
        cout << "Jumlah setor tunai tidak valid.\n";
        this_thread::sleep_for(chrono::seconds(1));
        return;
    }

    if (nasabah->saldo < jumlahSetorTunai) {
        cout << "Saldo Anda tidak mencukupi untuk melakukan setor tunai ini\n";
        this_thread::sleep_for(chrono::seconds(1));
        return;
    }

    nasabah->saldo += jumlahSetorTunai;

    string keterangan = "Setor Tunai";
    rekamTransaksi(nasabah, keterangan, jumlahSetorTunai);

    cout << "Setor Tunai berhasil dilakukan.\n";
    this_thread::sleep_for(chrono::seconds(1));
    return;
}

void menuUtama(Nasabah* head, Nasabah* nasabah) {
    while (true) {
        printJudul();
        cout << "[1] Cek Saldo\n";
        cout << "[2] Riwayat Transaksi\n";
        cout << "[3] Profile\n";
        cout << "[4] Transfer\n";
        cout << "[5] Setor Tunai\n";
        cout << "[6] Keluar\n";

        int inputPilihan;
        cout << "\n> ";
        cin >> inputPilihan;

        switch (inputPilihan) {
            case 1:
                cekSaldo(nasabah);
                break;
            case 2:
                tampilkanRiwayatTransaksi(nasabah);
                break;
            case 3:
                menuProfile(nasabah);
                break;
            case 4:
                menuTransfer(head, nasabah);
                break;
            case 5:
                menuSetortunai(head, nasabah);
                break;
            case 6:
                return;
            default:
                cout << "Tolong input pilihan dengan benar\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
        }
    }
}

void menuDaftar(Nasabah*& head) {
    string nama;
    while (true) {
        printJudul();
        cout << "Menu Daftar\n\n";

        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, nama);

        if (isNamaTerdaftar(head, nama)) {
            cout << "Nama sudah terdaftar. Silakan gunakan nama yang berbeda.\n";
            this_thread::sleep_for(chrono::seconds(1));
        } else {
            break;
        }
    }

    int pin;
    cout << "Masukkan PIN: ";
    cin >> pin;

    int saldo;
    cout << "Masukkan Setor Tunai Awal (minimal 500000): Rp. ";
    cin >> saldo;

    int nomorKartu = generateNomorKartu();

    Nasabah* newNasabah = new Nasabah;
    newNasabah->nama = nama;
    newNasabah->pin = pin;
    newNasabah->nomorKartu = nomorKartu;
    newNasabah->saldo = saldo;
    newNasabah->prev = nullptr;
    newNasabah->next = nullptr;

    if (head == nullptr) {
        head = newNasabah;
    } else {
        Nasabah* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNasabah;
        newNasabah->prev = temp;
    }

    cout << "\nPendaftaran berhasil!\n";
    cout << "Nomor Kartu Anda: " << nomorKartu << endl;

    cout << "\nTekan ENTER untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void menuMasuk(Nasabah* head) {
    printJudul();
    cout << "Menu Masuk\n\n";

    int nomorKartu, pin;
    cout << "Masukkan Nomor Kartu: ";
    cin >> nomorKartu;
    cout << "Masukkan PIN: ";
    cin >> pin;

    Nasabah* nasabah = cariNasabah(head, nomorKartu, pin);
    if (nasabah == nullptr) {
        cout << "Nomor Kartu atau PIN salah.\n";
        this_thread::sleep_for(chrono::seconds(1));
    } else {
        cout << "Selamat datang, " << nasabah->nama << "!\n";
        this_thread::sleep_for(chrono::seconds(1));
        menuUtama(head, nasabah);
    }
}

void cetakSemuaNasabah(Nasabah* head) {
    Nasabah* temp = head;

    if (temp == nullptr) {
        cout << "Tidak ada nasabah yang terdaftar." << endl;
        return;
    }

    cout << "Data Nasabah:" << endl;

    while (temp != nullptr) {
        cout << "Nama: " << temp->nama << endl;
        cout << "Nomor Kartu: " << temp->nomorKartu << endl;
        cout << "PIN: " << temp->pin << endl;
        cout << "Saldo: " << temp->saldo << endl;
        cout << "---------------------" << endl;
        temp = temp->next;
    }
}

int main() {
    srand(time(0));  

    Nasabah* head = nullptr;

    while (true) {
        printJudul();

        cetakSemuaNasabah(head);
        
        cout << "\n[1] Daftar\n";
        cout << "[2] Masuk\n";
        cout << "[3] Keluar\n";

        int inputPilihan;
        cout << "\n> "; 
        cin >> inputPilihan;

        switch (inputPilihan) {
            case 1:
                menuDaftar(head);
                break;
            case 2:
                menuMasuk(head);
                break;
            case 3:
                cout << "Terima kasih telah menggunakan layanan kami. Sampai jumpa!\n";
                exit(0); 
            default:
                cout << "Tolong input angka 1, 2, atau 3.\n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
        }
    }

    return 0;
}
