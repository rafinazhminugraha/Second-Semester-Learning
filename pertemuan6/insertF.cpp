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
        head = newNode;
    }
}

void printList()
{
    if(!isEmpty())
    {
        node *n;
        n = head;
        
        while (n != NULL)
        {
            cout << n->data << " ";
            n = n->next;
        }
        
    }
}


int main()
{
    head = NULL;
    insertFirst(1);
    insertFirst(2);
    insertFirst(3);
    insertFirst(4);
    printList();

}
