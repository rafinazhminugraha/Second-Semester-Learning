#include <iostream>
#include <malloc.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head;
node *tail;

bool isEmpty()
{
    if(head==NULL)
    {
        return true;
    }
    return false;
}


void insertLast(int nilai)
{
    node *newNode;
    node *current;

    newNode = new node;
    newNode->data = nilai;
    newNode->next = NULL;

    if (isEmpty())
    {
        head = newNode;
        head->next = NULL;
    }
    else
    {
        current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    
}

void printList()
{
    node *n;
    n = head;
    
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}


int main()
{
    head = NULL;
    insertLast(1);
    insertLast(2);
    insertLast(3);
    insertLast(4);
    printList();

}
