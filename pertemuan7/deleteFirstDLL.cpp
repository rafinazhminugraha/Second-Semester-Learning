#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

node *head = NULL;
node *tail = NULL;

bool isEmpty()
{
    return (head == NULL);
}

void insertFirst(int nilai)
{
    node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = nilai;
    newNode->prev = NULL;

    if (isEmpty())
    {
        newNode->next = NULL;
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void deleteFirst()
{
    if (isEmpty())
    {
        cout << "List kosong, tidak ada yang bisa dihapus" << endl;
    }
    else
    {
        node *temp = head;

        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }

        free(temp);
    }
}

void cetakList()
{
    if (!isEmpty())
    {
        node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

int main()
{
    insertFirst(1);
    insertFirst(3);
    insertFirst(5);
    insertFirst(7);

    cout << "sebelum remove first:\n";
    cetakList();

    deleteFirst();
    cout << "sesudah remove first:\n";
    cetakList();

    return 0;
}
