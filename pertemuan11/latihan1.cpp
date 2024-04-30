#include <iostream>
using namespace std;

const int kapasitas = 10;
struct STACK
{
    int top;
    int temp[kapasitas];
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

void push(int data)
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

void pop()
{
    if (isEmpty() == 0)
    {
        STACK.top--;
        cout << "Data top sudah terhapus\n";
    }
    else
    {
        cout << "Stack Kosong!\n";
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

int main()
{
    createStack();

    for (int i = 0; i < kapasitas; i++)
    {
        int angkaTambahStack;
        cout << "Input angka untuk stack index ke-" << i << " = "; cin >> angkaTambahStack; 
        push(angkaTambahStack);
    }

    pop();
    pop();

    displayStack();

    int angkaCariStack;
    cout << "Cari angka = "; cin >> angkaCariStack;
    findStack(angkaCariStack);

    clearStack();
    displayStack();
    return 0;
}
