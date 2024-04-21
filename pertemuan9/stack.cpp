#include <iostream>
using namespace std;

const int kapasitas = 5;
struct stack
{
    int top;
    int temp[kapasitas];
}stack;

void createStack()
{
    stack.top = -1;
}

int isEmpty()
{
    if (stack.top == -1)
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
    if (stack.top == kapasitas - 1)
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
        cout << "maaf, stack sudah penuh";
    }
    else
    {
        stack.top++;
        stack.temp[stack.top] = data;
        cout << "Data " << stack.temp[stack.top] << " berhasil masuk kedalam stack" << endl;
    }   
}

void displayStack()
{
    if (isEmpty() == 0)
    {
        cout << "menampilkan isi stack: " << "\n";
        for (int i = stack.top; i >= 0; i--)
        {
            cout << "data index stack ke-" << i << " adalah " << stack.temp[i] << "\n";
        }
        cout << endl;   
    }
    else
    {
        cout << "maaf, tidak ada data pada stack" << "\n";
    }
}

int main()
{
    int data;
    createStack();
    cout << "push data:\n";
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    cout << "\n\n";
    displayStack();

    return 0;
}
