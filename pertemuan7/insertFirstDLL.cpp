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
    newNode = (struct node *)malloc(sizeof(struct node));
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
    insertFirst(1);
    insertFirst(3);
    insertFirst(5);
    insertFirst(7);

    cetakList();

    return 0;
}
