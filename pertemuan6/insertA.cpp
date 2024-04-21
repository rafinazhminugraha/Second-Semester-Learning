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


// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// void insertAfter(Node* prevNode, int nilai) {
//     if (prevNode == NULL) {
//         cout << "The given previous node cannot be NULL";
//         return;
//     }

//     Node* newNode = new Node();
//     newNode->data = nilai;

//     newNode->next = prevNode->next;
//     prevNode->next = newNode;
// }

// void printList(Node* node) {
//     while (node != NULL) {
//         cout << node->data << " ";
//         node = node->next;
//     }
// }

// int main() {
//     Node* head = NULL;
//     Node* second = NULL;
//     Node* third = NULL;

//     head = new Node();
//     second = new Node();
//     third = new Node();

//     head->data = 1;
//     head->next = second;

//     second->data = 2;
//     second->next = third;

//     third->data = 3;
//     third->next = NULL;

//     insertAfter(second, 4);

//     printList(head);

//     return 0;
// }
