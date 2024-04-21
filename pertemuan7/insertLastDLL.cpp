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

void insertLast(int nilai)
{
    node *newNode; newNode = new node;
    newNode->data = nilai;
    newNode->next = NULL;

    if (isEmpty())
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        
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
    insertLast(1);
    insertLast(3);
    insertLast(5);
    insertLast(7);

    cetakList();

    return 0;
}