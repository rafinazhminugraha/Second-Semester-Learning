#include <iostream>
using namespace std;

const int kapasitas = 5;
struct STACK
{
    int top;
    int temp[kapasitas];
}STACK;

void createStack()
{
    STACK.top = -1;
}

int isEmpty()
{
    if (STACK.top = -1)
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
        cout << "Data " << STACK.temp[STACK.top] << " berhasil masuk ke dalam stack\n";
    }
}

void displayStuck()
{
    if (isEmpty() == 0)
    {
        cout << "Menampilkan isi stack: \n";
        for (int i = STACK.top; i > -1; i--)
        {
            cout << "Stack [" << i << "] adalah " << STACK.temp[i] << "\n";
        }
        cout << "\n";
    }
    else
    {
        cout << "Tidak ada data dalam stack!\n";
    }
}

void pop()
{
    if (isEmpty == 0)
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
    cout << "Stack dibersihkan!";
}

void findStack(int data)
{
    int tmp, itmp;
    if (isEmpty() == -1)
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
            }

        }
        if (data == tmp)
        {
            cout << "Data " << data << " di temukan di index ke-" << itmp << "\n";
        }
        else
        {
            cout << data << "tidak ada data yang sesuai dalam stack\n";
        }
    }
}