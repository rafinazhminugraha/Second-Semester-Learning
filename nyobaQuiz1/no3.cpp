#include <iostream>
#include <ctime>

using namespace std;

int main() {
	
    string pilihanUser;
    cout << "gunting / batu / kertas (gunakan huruf kecil)";
    cout << "\nkamu memilih : ";
    cin >> pilihanUser;

    string pilihanCom;
	srand(time(0));
	int randomAngka = rand() % 3 + 1;
    
    switch (randomAngka)
    {
    case 1:
        pilihanCom = "gunting";
        cout << "komputer memilih : gunting\n";
        break;
    case 2:
        pilihanCom = "batu";
        cout << "komputer memilih : batu\n";
        break;
    case 3:
        pilihanCom = "kertas";
        cout << "komputer memilih : kertas\n";
        break;
    }

    if (pilihanUser == pilihanCom)
    {
        cout << "SERI! kamu dan komputer memilih pilihan yang sama";
    }
    else if (pilihanUser == "gunting" && pilihanCom == "batu")
    {
        cout << "KAMU KALAH! dan komputer menang";
    }
    else if (pilihanUser == "batu" && pilihanCom == "kertas")
    {
        cout << "KAMU KALAH! dan komputer menang";
    }
    else if (pilihanUser == "kertas" && pilihanCom == "gunting")
    {
        cout << "KAMU KALAH! dan komputer menang";
    }
    else if (pilihanUser == "gunting" && pilihanCom == "kertas")
    {
        cout << "KAMU MENANG! dan komputer KALAAH";
    }
    else if (pilihanUser == "batu" && pilihanCom == "gunting")
    {
        cout << "KAMU MENANG! dan komputer KALAAH";
    }
    else if (pilihanUser == "kertas" && pilihanCom == "gunting")
    {
        cout << "KAMU MENANG! dan komputer KALAAH";
    }
    else
    {
        cout << "...\nTidak menang ataupun kalah, input yang benar!";
    }
    
    
}
    
