#include <iostream>
#include <conio.h> // Menggunakan conio.h untuk getch() pada Windows

std::string getPassword() {
    std::string password;
    char ch;

    std::cout << "Masukkan password: ";
    while (true) {
        ch = _getch(); // Menggunakan _getch() untuk membaca karakter tanpa menampilkannya
        if (ch == 13) // 13 adalah kode ASCII untuk Enter
            break;
        else if (ch == 8) // 8 adalah kode ASCII untuk Backspace
        {
            if (!password.empty())
            {
                std::cout << "\b \b"; // Menghapus karakter dari layar
                password.pop_back(); // Menghapus karakter dari string password
            }
        }
        else
        {
            password.push_back(ch); // Menambah karakter ke string password
            std::cout << '*'; // Menampilkan bintang sebagai ganti karakter
        }
    }
    std::cout << std::endl;
    return password;
}

int main() {
    std::string password = getPassword();
    std::cout << "Password yang dimasukkan: " << password << std::endl;

    return 0;
}
