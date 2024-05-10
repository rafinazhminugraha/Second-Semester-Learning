#include <iostream>
using namespace std;

const int kapasitas = 3;

struct Stack 
{
    int top;
    string isi[kapasitas];
};

Stack Tabung1;
Stack Tabung2;
Stack Tabung3;
Stack Tabung4;

void membuatStack(Stack& Stack) 
{
    Stack.top = -1;
}

int kosong(Stack& Stack) 
{
    if (Stack.top == -1) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

int penuh(Stack& Stack) 
{
    if (Stack.top == kapasitas - 1) 
    {
        return 1;
    } 
    else 
    {
        return 0;
    }
}

void push(Stack& Stack, const string& data) 
{
    if (penuh(Stack) == 1) 
    {
        cout << "Data stack sudah penuh" << endl;
    } 
    else 
    {
        Stack.top++;
        Stack.isi[Stack.top] = data;
    }
}

void tampilkanStack(Stack& Stack) 
{
    if (kosong(Stack) == 0) 
    {
        for (int i = Stack.top; i >= 0; i--) 
        {
            cout << "Bola index stack ke-" << i << " berwarna " << Stack.isi[i] << endl;
        } cout << endl;
    } 
    else 
    {
        cout << "Tidak ada data pada stack." << endl << endl;
    }
}

void pindahkanBola(Stack& StackAsal, Stack& StackTujuan) 
{
    if (kosong(StackAsal) == 0) 
    {
        push(StackTujuan, StackAsal.isi[StackAsal.top]);
        StackAsal.top--;
    } 
    else 
    {
        cout << "Tidak ada data pada stack." << endl;
    }
}

int main() 
{
    membuatStack(Tabung1);
    membuatStack(Tabung2);
    membuatStack(Tabung3);
    membuatStack(Tabung4);

    push(Tabung1, "Biru");
    push(Tabung1, "Ungu");
    push(Tabung1, "Hijau");

    push(Tabung2, "Ungu");
    push(Tabung2, "Ungu");
    push(Tabung2, "Hijau");

    push(Tabung3, "Hijau");
    push(Tabung3, "Biru");
    push(Tabung3, "Biru");
    cout << endl;

    cout << "======================\n";
    cout << "Sebelum bola di susun: \n";
    cout << "======================\n\n";
    cout << "Tabung 1: " << endl;
    tampilkanStack(Tabung1);
    cout << "Tabung 2: " << endl;
    tampilkanStack(Tabung2);
    cout << "Tabung 3: " << endl;
    tampilkanStack(Tabung3);
    cout << "Tabung 4: " << endl;
    tampilkanStack(Tabung4);
    cout << endl;

    pindahkanBola(Tabung1, Tabung4);
    pindahkanBola(Tabung2, Tabung4);
    pindahkanBola(Tabung1, Tabung2);
    pindahkanBola(Tabung3, Tabung1);
    pindahkanBola(Tabung3, Tabung1);
    pindahkanBola(Tabung3, Tabung4);

    cout << endl;

    cout << "\n======================\n";
    cout << "Setelah bola di susun: \n";
    cout << "======================\n\n";
    cout << "Tabung 1: " << endl;
    tampilkanStack(Tabung1);
    cout << "Tabung 2: " << endl;
    tampilkanStack(Tabung2);
    cout << "Tabung 3: " << endl;
    tampilkanStack(Tabung3);
    cout << "Tabung 4: " << endl;
    tampilkanStack(Tabung4);

    return 0;
}