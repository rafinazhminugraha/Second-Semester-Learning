#include <iostream>
#include <malloc.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

node *head;
node *tail;
node *current = NULL;

bool isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    return false;
};

void insertFirst(int nilai)
{
    node *newNode;
    newNode = new node;
    newNode->data = nilai;

    if (isEmpty())
    {
        head = newNode;
        head->next = NULL;
    }
    else
    {
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
    }
};

void insertAfter(struct node *nextNode, int nilai)
{
    if (nextNode == NULL)
    {
        cout << "nilai sebelumnya tidak boleh NULL";
        return;
    }
    node *newNode = new node;
    newNode->data = nilai;

    if (isEmpty())
    {
        newNode->prev->next = newNode;
    }
    else
    {
        newNode->prev = nextNode->prev;
        nextNode->prev = newNode;
        newNode->next = nextNode;
        head->next = newNode;
    }
}

void cetakList()
{
    if (!isEmpty())
    {
        node *current;
        current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    head = NULL;

    insertFirst(7);
    insertFirst(5);
    insertFirst(1);

    cout << "sebelum insert:" << endl;
    cetakList();cout << "\n";

    insertAfter(head->next, 3);
    cout << "setelah insert:" << endl;
    cetakList();cout << "\n";


    return 0;
}
