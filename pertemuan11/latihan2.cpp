#include <iostream>
#include <cstring>
using namespace std;

const int kapasitas = 100;
struct STACK
{
    int top;
    char temp[kapasitas];
} STACK;

void createStack()
{
    STACK.top = -1;
}

int isEmpty()
{
    if (STACK.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (STACK.top == kapasitas - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char data)
{
    if (isFull() == 1)
    {
        cout << "maaf stack sudah penuh";
    }
    else
    {
        STACK.top++;
        STACK.temp[STACK.top] = data;
    }
}

void displayStack()
{
    if (isEmpty() == 0)
    {
        cout << "\nMenampilkan isi stack: \n";
        for (int i = STACK.top; i > -1; i--)
        {
            cout << "Stack [" << i << "] adalah " << STACK.temp[i] << "\n";
        }
        cout << "\n";
    }
    else
    {
        cout << "\nTidak ada data dalam stack!\n";
    }
}

char pop()
{
    if (isEmpty() == 0)
    {
        char data = STACK.temp[STACK.top];
        STACK.top--;
        return data;
    }
    else
    {
        cout << "Stack Kosong!\n";
        return -1;
    }
}

void clearStack()
{
    STACK.top = -1;
    cout << "Stack dibersihkan!\n";
}

void findStack(int data)
{
    int tmp = -1, itmp = -1;
    if (isEmpty() == 1)
    {
        cout << "Stack masih kosong!";
    }
    else
    {
        for (int i = STACK.top; i > -1; i--)
        {
            if (data == STACK.temp[i])
            {
                tmp = data;
                itmp = i;
                break;
            }
        }
        if (data == tmp)
        {
            cout << "\nData " << data << " ditemukan di index ke-" << itmp << "\n";
        }
        else
        {
            cout << "\n" << data << " tidak ada data yang sesuai dalam stack\n";
        }
    }
}

void swapKata(const char *kalimat)
{
    int length = strlen(kalimat);
    if (length > kapasitas)
    {
        std::cout << "Kalimat terlalu panjang\n";
        return;
    }

    for (int i = 0; i < length; i++)
    {
        push(kalimat[i]);
    }

    cout << "Kalimat terbalik: ";
    while (isEmpty() == 0)
    {
        cout << pop();
    }
    cout << std::endl;
}

int main()
{
    createStack();
    char kalimat[100];
    cout << "Masukkan kalimat (max 100 karakter): "; cin.getline(kalimat, 100);
    swapKata(kalimat);
    return 0;
}