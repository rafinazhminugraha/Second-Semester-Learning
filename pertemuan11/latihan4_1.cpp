#include <iostream>
using namespace std;

const int kapasitas = 5;
struct STACK
{
    int top;
    int temp[kapasitas];
};

void createStack(STACK &s)
{
    s.top = -1;
}

int isEmpty(STACK &s)
{
    if (s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(STACK &s)
{
    if (s.top == kapasitas - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

void push(STACK &s, int data)
{
    if (isFull(s) == 1)
    {
        cout << "maaf stack sudah penuh";
    }
    else
    {
        s.top++;
        s.temp[s.top] = data;
        cout << "Data " << s.temp[s.top] << " berhasil masuk ke dalam stack\n";
    }
}

void displayStack(STACK &s)
{
    if (isEmpty(s) == 0)
    {
        cout << "Menampilkan isi stack: \n";
        for (int i = s.top; i > -1; i--)
        {
            cout << "Stack [" << i << "] adalah " << s.temp[i] << "\n";
        }
        cout << "\n";
    }
    else
    {
        cout << "Tidak ada data dalam stack!\n";
    }
}

void pop(STACK &s)
{
    if (isEmpty(s) == 0)
    {
        s.top--;
        cout << "Data top sudah terhapus\n";
    }
    else
    {
        cout << "Stack Kosong!\n";
    }
}

void clearStack(STACK &s)
{
    s.top = -1;
    cout << "Stack dibersihkan!";
}

void findStack(STACK &s, int data)
{
    int tmp, itmp;
    if (isEmpty(s) == -1)
    {
        cout << "Stack masih kosong!";
    }
    else
    {
        for (int i = s.top; i > -1; i--)
        {   
            if (data == s.temp[i])
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

int main() {
    STACK s1, s2;
    createStack(s1);
    createStack(s2);

    // Contoh pemindahan data antar stack
    push(s1, 10);
    push(s2, s1.temp[s1.top]);
    pop(s1);

    displayStack(s1);
    displayStack(s2);

    return 0;
}
